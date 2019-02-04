#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace std;

// The main entry point for the application.
auto main() -> int {
  random_device rand;
  vector<string> male_pet_names = {"Rufus", "Bear", "Dakota", "Fido", "Vanya", "Samuel", "Koani", "Volodya", "Prince", "Yiska"};
  vector<string> female_pet_names = {"Maggie", "Penny", "Saya", "Princess", "Abby", "Laila", "Sadie", "Olivia", "Starlight", "Talla"};

  // Generate random indexes for pet names.
  size_t m_index = uniform_int_distribution<size_t> {0, male_pet_names.size() - 1}(rand);
  size_t f_index = uniform_int_distribution<size_t> {0, female_pet_names.size() - 1}(rand);

  // Display the result.
  cout << "Suggested pet name of the day: " << endl;
  cout << "   For a male:     " << male_pet_names[m_index] << endl;
  cout << "   For a female:   " << female_pet_names[f_index] << endl;
}

// This code produces the following output:
//
// Suggested pet name of the day:
//    For a male:     Fido
//    For a female:   Princess
