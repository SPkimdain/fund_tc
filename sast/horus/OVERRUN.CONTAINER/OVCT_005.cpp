#include <algorithm>
#include <vector>

/* OVCT_005 - assigned size. */

int OVCT_005_function(int flag, std::vector<int>& v) {
  int ret = 0;

  if(flag > 10) {
    std::fill_n(v.begin(), 10, 0x42); //It's ok.
  }
  else {
    ret++;
  }

  return ret;
}

int OVCT_005_size() {
  return 10;
}

int OVCT_005_functio2(int flag) {
  const int size = OVCT_005_size();
  int ret = 0;

  std::vector<int> v(size);

  if(flag > 10) {
    std::fill_n(v.begin(), 15, 0x42); //@violation OVERRUN.CONTAINER
  }
  else {
    ret++;
  }

  return ret;
}

