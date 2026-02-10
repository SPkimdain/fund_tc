
/* TOS_061 - 2dem array2 */
struct TOS_061_Struct {
  int gmap[3][5];
};

int TOS_061_function1(int* s, int x, int y) {
  int i2 = 0;
  i2 = *(s + (x + y));
  return i2;
}

void TOS_061_function2() {
  TOS_061_Struct obj;
  obj.gmap[2][4] = 100;
  
  int x = 0;
  int y = 0;
  
  x = 2 * 5;
  y = 4;
  TOS_061_function1(&obj.gmap[0][0], x, y); //It's ok.
  
  x = 4 * 5;
  y = 2;
  TOS_061_function1(&obj.gmap[0][0], x, y); //@violation TYPE_OVERRUN.STATIC
}

