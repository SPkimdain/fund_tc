#include <vector>

/* OVCT_008 - container operator[] case 2. */
using namespace std;

int OVCT_008_function(int flag) {
  if(flag > 10) {
    return 10;
  }
  else {
    return -1;
  }
}

void OVCT_008_function2(vector<int>& cont) {

  int ret = OVCT_008_function(20);
  cont[ret] = 20; //It's ok.

  int ret2 = OVCT_008_function(2);
  cont[ret2] = 10; //@violation OVERRUN.CONTAINER
}
