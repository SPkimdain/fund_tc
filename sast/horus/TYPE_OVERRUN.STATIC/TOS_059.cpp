
/* TOS_059 - 2dem array */
struct TOS_059_Struct {
  int gmap[3][5];
  int gmap2[5];
};

int TOS_059_function1(TOS_059_Struct& obj) {
  obj.gmap[2][4] = 10; //It's ok.
  obj.gmap2[3] = 20;   
  
  obj.gmap[3][2] = 100; //@violation TYPE_OVERRUN.STATIC
  
  return 0;
}
