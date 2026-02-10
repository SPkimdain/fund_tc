
/* UN_063 - call by reference2 */

void UN_063_function1(int x, int y, int& xOut, int& yOut, int max) {
  xOut = x;
  yOut = y;

  int count = 0;
  while(count < max) {
    xOut = x + count;
    yOut = y;
    count++;
  }
}

int UN_063_function2() {
  int xEnd, yEnd;
  
  UN_063_function1(0, 0, xEnd, yEnd, 100);
  
  int ret = xEnd; //It's ok.  
  
  int a;
  int b;
  b = a; //@violation UNINIT 
  
  return ret;
}
