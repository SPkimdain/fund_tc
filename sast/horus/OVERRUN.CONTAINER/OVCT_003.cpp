#include <algorithm>
#include <vector>

/* OVCT_003 - simple case3 */
int OVCT_003_function1(int flag) {
  int ret = 0;

  std::vector<int> v(10);

  if(flag > 10) {
    std::fill_n(v.begin(), 5, 0x42); //It's ok.
  }
  else {
    ret++;
  }

  return ret;
}

int OVCT_003_function2(int flag) {
  int ret = 0;

  std::vector<int> v(5);

  if(flag > 10) {
    std::fill_n(v.begin(), 10, 0x42); //@violation OVERRUN.CONTAINER
  }
  else {
    ret++;
  }

  return ret;
}

