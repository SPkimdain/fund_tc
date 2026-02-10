#include <array>

/* OVCT_011 - container operator[] case 4 - array. */
using namespace std;

int OVCT_011_function(int flag) {
  if(flag > 10) {
    return 10;
  }
  else {
    return 0;
  }
}

void OVCT_011_function2(array<int, 8>& cont) {

  int ret = OVCT_011_function(5);
  cont[ret] = 20; //It's ok.

  ret--;

  cont[ret] = 10; //@violation OVERRUN.CONTAINER
}
