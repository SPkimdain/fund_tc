#ifdef _WIN32
#pragma warning(disable:4996)
#endif

#include <cstdlib>
#include <string>

/* NDMC_016 getenv() failed */

void NDMC_016_function() {
  const char* info = std::getenv("TMP");
  if(info == 0) { //wrong compare
    std::string tmp(info); /* @violation NULL_DEREF.MISSING_CHECK */
    if(!tmp.empty()) {
      // ...
      return;
    }
  }
}
