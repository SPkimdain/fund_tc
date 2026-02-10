
/* UN_061 - sizeof */

void UN_061_funciton() {
  int* x;
  int len = sizeof(*x); //It's ok.
  
  int a;
  int b;
  b = a; //@violation UNINIT

}
