#include <iostream>

/* INT_004 - tainted value */
using namespace std;

void INT_004_function(std::istream& in) {
  char buffer[32];
  try {
    in.read(buffer, sizeof(buffer));
  }
  catch(std::ios_base::failure& e) {
    return;
  }


  std::string str(buffer); //@violation IMPROPER_NULL_TERMINATION

  std::string str2(buffer, in.gcount());
}
