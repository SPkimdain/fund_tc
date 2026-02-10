#pragma warning(disable : 4700)

/* UN_007 - Function call */
int UN_007_function1(int arg, int arg2) {
  int ret = 0;
  ret += arg2; //It's ok.
  ret += arg; 
  
  return ret;
}

void UN_007_function2() {
  int x;
  int y = 10;
  UN_007_function1(x, y); 	//@violation UNINIT
}
