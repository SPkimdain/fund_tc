
/* OV_060 - 3dem array */
int OV_060_function1() {

  int gmap[2][3][4] = { 1, };
  
  int i2 = 0;
  i2= gmap[0][2][3];   //It's ok.

  i2 = gmap[2][1][0];  //@violation OVERRUN.STATIC
  
  return i2;
}
