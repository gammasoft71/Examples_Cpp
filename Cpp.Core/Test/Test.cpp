#include <exception>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

// In the GNU C Library, "major" is defined by <sys/sysmacros.h>. For historical compatibility, it is currently defined by <sys/types.h> as well, 
// but we plan to remove this soon. To use "major", include <sys/sysmacros.h> directly. If you did not intend to use a system-defined macro "major",
// you should undefine it after including <sys/types.h>.
#undef major

// In the GNU C Library, "minor" is defined by <sys/sysmacros.h>. For historical compatibility, it is currently defined by <sys/types.h> as well, 
// but we plan to remove this soon. To use "minor", include <sys/sysmacros.h> directly. If you did not intend to use a system-defined macro "minor",
// you should undefine it after including <sys/types.h>.
#undef minor

class version final {
public:
  version() = default;
  version(int major, int minor) : major_(major), minor_(minor) {}
  version(int major, int minor, int build) : major_(major), minor_(minor), build_(build) {}
  version(int major, int minor, int build, int revision) : major_(major), minor_(minor), build_(build), revision_(revision) {}
  version(const version&) = default;
  version& operator=(const version&) = default;

  int build() const {return this->build_;}
  int major() const {return this->major_;}
  int16_t major_revision() const {return (int16_t)((this->revision_ & 0xFFFF0000) >> 16);}
  int minor() const {return this->minor_;}
  int16_t mainor_revision() const {return (int16_t)(this->revision_ & 0x0000FFFF);}
  int revision() const {return this->revision_;}

  static version parse(const std::string& ver) {
    std::regex rgx("\\.");
    std::vector<std::string> versions;
    for (std::sregex_token_iterator it(ver.begin(), ver.end(), rgx, -1), end; it != end; ++it)
      versions.push_back(*it);

    switch (versions.size()) {
      case 2: return version(std::stoi(versions[0]), std::stoi(versions[1]));
      case 3: return version(std::stoi(versions[0]), std::stoi(versions[1]), std::stoi(versions[2]));
      case 4: return version(std::stoi(versions[0]), std::stoi(versions[1]), std::stoi(versions[2]), std::stoi(versions[3]));
    }
    throw std::invalid_argument("bad format");
  }

  static bool try_parse(const std::string& ver, version& result) {
    try {
      result = parse(ver);
      return true;
    } catch (...) {
      return false;
    }
  }

  std::string to_string() const {
    return this->to_string(2 + (this->build_ != -1 ? 1 : 0) + (this->revision_ != -1 ? 1 : 0));;
  }

  std::string to_string(size_t field_count) const {
    if (field_count > 4 || (field_count >= 3 && this->build_ == -1) || (field_count == 4 && this->revision_ == -1))
      throw std::invalid_argument("field_count invalid");
    std::stringstream result;
    if (field_count >= 1)
      result << std::to_string(this->major_);
    if (field_count >= 2)
      result << "." << std::to_string(this->minor_);
    if (field_count >= 3)
      result << "." << std::to_string(this->build_);
    if (field_count == 4)
      result << "." << std::to_string(this->revision_);
    return result.str();
}
  
  friend std::ostream& operator <<(std::ostream& os, const version& ver) {
  return os << ver.to_string();
}

private:
  int major_ = 0;
  int minor_ = 0;
  int build_ = -1;
  int revision_ = -1;
};

using namespace std;

auto main() -> int {
  //cout << "Hello, World!" << endl;

  version v1(1, 2, 3);
  cout << "v1 = " << v1 << endl;

  version v2 = version::parse("10.11.12");
  cout << "v2 = " << v2 << endl;
}
