#include <algorithm>
#include <vector>
#include <string>

/* OVCT_006 - string case */

void OVCT_006_function(std::string& src) {
  std::string dest;

  std::copy(src.begin(), src.end(), dest.begin()); //@violation OVERRUN.CONTAINER

  int x = 0;

  x++;

  return;
}
