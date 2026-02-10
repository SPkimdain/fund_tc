#include <vector>

/* OVCT_010 - Custom container operator[] bad_cond case test. */
using namespace std;

class Custom_container_test {
public:
  int& operator[](int index);
};

int OVCT_010_function(Custom_container_test& cont, int i) {

  if(i > 256) {
    return -1;
  }
  else if(i < -3) { // [min, -4]
    cont[i] = 100;  //@violation OVERRUN.CONTAINER
  }
  else {}

  return 0;
}

