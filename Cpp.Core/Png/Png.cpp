#include <cstdio>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <png.h>

enum class PngColorType {
  Gray = PNG_COLOR_TYPE_GRAY,
  Palette = PNG_COLOR_TYPE_PALETTE,
  Rgb = PNG_COLOR_TYPE_RGB,
  RgbAlpha = PNG_COLOR_TYPE_RGB_ALPHA,
  GrayAlpha = PNG_COLOR_TYPE_GRAY_ALPHA
};

class Png {
public:
  Png(const Png& png)  {}
  
  static Png LoadFromFile(const std::string& fileName) {
    Png png;
    FILE *fp = fopen(fileName.c_str(), "rb");
    
    png_structp pngStruct = png_create_read_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if(!pngStruct)
      throw std::runtime_error("Png create read struct error");
    
    png_infop info = png_create_info_struct(pngStruct);
    if(!info) {
      png_destroy_read_struct(&pngStruct, nullptr, nullptr);
      throw std::runtime_error("Png create info struct error");
    }
    
    if(setjmp(png_jmpbuf(pngStruct))) {
      png_destroy_read_struct(&pngStruct, &info, nullptr);
      throw std::runtime_error("set jump error");
    }
    
    png_init_io(pngStruct, fp);
    png_read_info(pngStruct, info);
    
    png.width = png_get_image_width(pngStruct, info);
    png.height = png_get_image_height(pngStruct, info);
    png.colorType = (PngColorType)png_get_color_type(pngStruct, info);
    png.bitDepth = png_get_bit_depth(pngStruct, info);
    
    if(png.bitDepth == 16)
      png_set_strip_16(pngStruct);
    if(png.colorType == PngColorType::Palette)
      png_set_palette_to_rgb(pngStruct);
    if(png.colorType == PngColorType::Gray && png.bitDepth < 8)
      png_set_expand_gray_1_2_4_to_8(pngStruct);
    if(png_get_valid(pngStruct, info, PNG_INFO_tRNS))
      png_set_tRNS_to_alpha(pngStruct);
    if(png.colorType == PngColorType::Rgb || png.colorType == PngColorType::Gray || png.colorType == PngColorType::Palette)
      png_set_filler(pngStruct, 0xFF, PNG_FILLER_AFTER);
    if(png.colorType == PngColorType::Gray || png.colorType == PngColorType::GrayAlpha)
      png_set_gray_to_rgb(pngStruct);
    
    png_read_update_info(pngStruct, info);
    
    png_bytep* rows = new png_bytep[sizeof(png_bytep) * png.height];
    size_t rowBytes = png_get_rowbytes(pngStruct, info);
    for(int row = 0; row < png.height; row++)
      rows[row] = new png_byte[rowBytes];
    png_read_image(pngStruct, rows);

    png.rawData = std::vector<std::uint8_t>(png.height * png_get_rowbytes(pngStruct, info));
    std::vector<std::uint8_t>::iterator iterator = png.rawData.begin();
    for(int row = 0; row < png.height; row++) {
      for(int rowByte = 0; rowByte < (int)rowBytes; rowByte++) {
        *iterator = rows[row][rowBytes];
        iterator++;
      }
    }
    
    for(int row = 0; row < png.height; row++)
      delete[] rows[row];
    delete[] rows;

    fclose(fp);
    return png;
  }
  
  void SaveToFile(const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if(!fp)  throw std::runtime_error("open file error");;
    
    png_structp png = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);
    if (!png)  throw std::runtime_error("png create write struct error");;
    
    png_infop info = png_create_info_struct(png);
    if (!info)  throw std::runtime_error("png create info struct error");
    
    if (setjmp(png_jmpbuf(png))) throw std::runtime_error("set jump error");
    
    png_init_io(png, fp);
    
    png_set_IHDR(png, info, width, height, 8, PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
    png_write_info(png, info);
    
    // To remove the alpha channel for PNG_COLOR_TYPE_RGB format, use png_set_filler().
    //png_set_filler(png, 0, PNG_FILLER_AFTER);
    
    //png_write_image(png, rowPointers);
    png_write_end(png, nullptr);
    
    fclose(fp);
  }
  
  int32_t Height() const {return this->height;}
  void Height(int32_t height) {this->height = height;}
  
  int32_t Width() const {return this->width;}
  void Width(int32_t width) {this->width = width;}

  PngColorType ColorType() const {return this->colorType;}
  void ColorType(PngColorType colorType) {this->colorType = colorType;}

  uint8_t BitDepth() const {return this->bitDepth;}
  void BitDepth(uint8_t bitDepth) {this->bitDepth = bitDepth;}

  const std::vector<uint8_t>& RawData() const {return this->rawData;}
  std::vector<uint8_t>& RawData() {return this->rawData;}

private:
  Png() {};
  int32_t height = 0;
  int32_t width = 0;
  PngColorType colorType = PngColorType::Gray;
  uint8_t bitDepth = 0;
  std::vector<uint8_t> rawData;
};

int main(int argc, char* argv[]) {
  if(argc != 3) throw std::invalid_argument("number of argument invalid (run PngTest fileToRead.png fileToWrite.png)");;

  Png png = Png::LoadFromFile(argv[1]);

  // Process png...
  for(int y = 0; y < png.Height(); y++) {
    png_bytep row = nullptr; //png.RowPointers()[y];
    for(int x = 0; x < png.Width(); x++) {
      // Do something awesome for each pixel here...
      png_bytep px = &(row[x * 4]);
      printf("%4d, %4d = RGBA(%3d, %3d, %3d, %3d)\n", x, y, px[0], px[1], px[2], px[3]);
    }
  }

  png.SaveToFile(argv[2]);
}
