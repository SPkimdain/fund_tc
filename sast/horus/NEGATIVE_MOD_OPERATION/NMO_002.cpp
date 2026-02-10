
/* NMO_002 - simple case2 */

int NMO_002_function(int x, int y) {
  if(x < 100) {
    return 0;
  }

  return x % y;
}


void NMO_002_function2() {
  int a = -10;
  int b = 5;

  NMO_002_function(b, a); //It's ok.

  int ret = NMO_002_function(1500, a);//@violation NEGATIVE_MOD_OPERATION
}
