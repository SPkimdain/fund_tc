#include <cstdlib>

/* NRDCL_002 - simple case, implicit return */

[[noreturn]] void NRDCL_002_function(int i) {
  if(i > 0) {
    throw "Recived positive input";
  }
  else if(i < 0) {
    std::exit(0);
  }
} //@violation NORETURN_DECLARED

[[noreturn]] void NRDCL_002_function2(int i) {
  if(i > 0) {
    throw "Recived positive input";
  }
  else {
    std::exit(0);
  }
} //It's ok.


