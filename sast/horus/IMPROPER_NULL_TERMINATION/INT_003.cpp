#include <iostream>

/* INT_003 - cin case. */

using namespace std;

void INT_003_function() {
  char buf[32];
  char* ptr = buf;
  
  cin >> ptr; //@violation IMPROPER_NULL_TERMINATION

}
