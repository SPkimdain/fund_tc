#include <cstdlib>

/* NRDCL_001 - simple case */

[[noreturn]] void NRDCL_001_function(int i) {
  if(i > 0) {
    throw "Recived positive input";
  }
  else if(i < 0) {
    std::exit(0);
  }

  return; //@violation NORETURN_DECLARED
} 

[[noreturn]] void NRDCL_001_function2(int i) {
  if(i > 0) {
    throw "Recived positive input";
  }
  else {
    std::exit(0);
  }
  return; //Impossible path. It's ok.
} 


