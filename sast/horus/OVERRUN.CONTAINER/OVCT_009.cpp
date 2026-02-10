#include <vector>

/* OVCT_009 - container operator[] case 3. */
using namespace std;

int OVCT_009_function(int flag) {
  if(flag > 10) {
    return 10;
  }
  else {
    return 0;
  }
}

void OVCT_009_function2(vector<int>& cont) {

  int ret = OVCT_009_function(5);
  cont.at(ret) = 20; //It's ok.
  
  ret--;

  cont.at(ret) = 10; //@violation OVERRUN.CONTAINER
}
