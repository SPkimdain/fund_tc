#include <fstream>
#include <string>

/* AIO_003 - fstream */


void AIO_003_function1(const std::string &fileName) {
  std::fstream file(fileName);
  if(!file.is_open()) {
    // Handle error
    return;
  }

  file << "Output some data";

  std::string str;

  file >> str; //@violation ALTERNATING_INPUT_OUTPUT 
}

void AIO_003_function2(const std::string &fileName) {
  std::fstream file(fileName);
  if(!file.is_open()) {
    // Handle error
    return;
  }

  file << "Output some data";

  std::string str;
  file.seekg(0, std::ios::beg);

  file >> str; //It's ok.
}
