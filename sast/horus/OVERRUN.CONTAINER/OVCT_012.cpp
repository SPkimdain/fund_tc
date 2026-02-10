#include <array>

/* OVCT_012 - container operator[] case 5 - array. */
using namespace std;

int OVCT_012_function(int flag) {
  if(flag > 10) {
    return 10;
  }
  else {
    return 0;
  }
}

void OVCT_012_function2(array<int, 8>& cont) {

  int ret = OVCT_012_function(5);
  cont.at(ret) = 20; //It's ok.

  ret--;

  cont.at(ret) = 10; //@violation OVERRUN.CONTAINER
}
