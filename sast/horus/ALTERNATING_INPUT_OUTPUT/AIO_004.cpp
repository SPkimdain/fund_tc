#include <fstream>
#include <string>

/* AIO_004 - fstream2 */
using std::string;


void AIO_004_function1(const std::string &fileName, int flag) {
  std::fstream file(fileName);
  if(!file.is_open()) {
    // Handle error
    return;
  }

  file << "Output some data";

  std::string str;
  if(flag > 10) {
    file.seekg(0, std::ios::beg);
  }
  else {
    flag++;
  
  }

  file >> str; //@violation ALTERNATING_INPUT_OUTPUT 
}

void AIO_004_function2(const std::string &fileName, const std::string& fileName2) {
  std::fstream file2(fileName2);
  
  std::fstream file(fileName);
  if(!file.is_open()) {
    // Handle error
    return;
  }

  if(file2.is_open() == false) {
    return;
  }

  file << "Output some data";

  std::string str;

  file2 >> str; //It's ok.
}
