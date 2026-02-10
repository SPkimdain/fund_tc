
/* OV_059 - 2dem array */
int OV_059_function1() {

  int gmap[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
  int gmap2[5] = { 0, 1, 2, 3, 4 };
  
  int i2 = 0;
  i2= gmap[2][4];   //It's ok.
  
  //i2 = gmap2[3]; // It's ok.

  i2 = gmap[3][2];  //@violation OVERRUN.STATIC
  
  return i2;
}
