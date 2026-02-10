
/* TOS_060 - 3dem array */
struct TOS_060_Struct {
  int gmap[2][3][4];
};

int TOS_060_function1() {
  TOS_060_Struct obj;
  int i2 = 100;
  obj.gmap[0][2][3] = i2;   //It's ok.

  obj.gmap[2][1][0] = i2 + 10;  //@violation TYPE_OVERRUN.STATIC
  
  return i2;
}
