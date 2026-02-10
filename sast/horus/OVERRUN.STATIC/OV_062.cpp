
/* OV_062 - 2dem array3 */
int OV_062_function1(int x, int y) {
  int gmap[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };    
  
  int i2 = 0;
  int a = 1;
  int b = 2;

  i2 += gmap[0][1];
  i2 += gmap[a][b];
  i2 += gmap[x][y];

  return i2;
}

int OV_062_function2() {
  int x = 0;
  int y = 0;
  
  x = 2;
  y = 4;
  int ret = OV_062_function1(x, y); //It's ok.
  
  x = 4;
  y = 2;
  ret = OV_062_function1(x, y); //@violation OVERRUN.STATIC

  return ret;
}

