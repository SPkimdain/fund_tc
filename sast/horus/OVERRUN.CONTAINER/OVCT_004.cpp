#include <algorithm>
#include <vector>
#include <iterator>

/* OVCT_004 - back_inserter */
void OVCT_004_function1(std::vector<int>& src) {
  std::vector<int> dest;
  std::copy(src.begin(), src.end(), std::back_inserter(dest)); //It's ok. 
  
  std::copy(src.begin(), src.end(), dest.begin()); //It's ok.

}


void OVCT_004_function2(std::vector<int>& src) {
  std::vector<int> dest;

  std::copy(src.begin(), src.end(), dest.begin()); //@violation OVERRUN.CONTAINER

  int x = 0;

  x++;

  return;
}
