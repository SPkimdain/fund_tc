
/* TOS_062 - 2dem array3 */
struct TOS_062_Struct {
  int gmap[3][5];
};

int TOS_062_function1(int x, int y) {  
  TOS_062_Struct obj;
  
  int i2 = 0;
  int a = 1;
  int b = 2;

  obj.gmap[0][1] = 10;
  obj.gmap[a][b] = 20;
  obj.gmap[x][y] = 30;

  return i2;
}

int TOS_062_function2() {
  int x = 0;
  int y = 0;
  
  x = 2;
  y = 4;
  int ret = TOS_062_function1(x, y); //It's ok.
  
  x = 4;
  y = 2;
  ret = TOS_062_function1(x, y); //@violation TYPE_OVERRUN.STATIC

  return ret;
}

