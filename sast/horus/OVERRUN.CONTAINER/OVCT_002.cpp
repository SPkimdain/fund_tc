#include <algorithm>
#include <vector>

/* OVCT_002 - simple case2 */

int OVCT_002_function(int flag) {
  int ret = 0;

  std::vector<int> v;
  
  if(flag > 10) {  
    std::fill_n(v.begin(), 10, 0x42); //@violation OVERRUN.CONTAINER
  }
  else {
    ret++;
  }
  
  return ret;
}

