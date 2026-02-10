
/* OV_061 - 2dem array2 */
int OV_061_function1(int* s, int x, int y) {
  
  int i2 = 0;
  i2 = *(s + (x + y));

  return i2;
}

void OV_061_function2() {
  int gmap[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };  
  int x = 0;
  int y = 0;
  
  x = 2 * 5;
  y = 4;
  OV_061_function1(&gmap[0][0], x, y); //It's ok.
  
  x = 4 * 5;
  y = 2;
  OV_061_function1(&gmap[0][0], x, y); //@violation OVERRUN.STATIC
}

