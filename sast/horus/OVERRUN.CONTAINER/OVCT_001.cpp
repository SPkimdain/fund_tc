#include <algorithm>
#include <vector>

/* OVCT_001 - simple case */

void OVCT_001_function(std::vector<int>& src) {
  std::vector<int> dest;

  std::copy(src.begin(), src.end(), dest.begin()); //@violation OVERRUN.CONTAINER

  int x = 0;
  
  x++;
  
  return;
}
