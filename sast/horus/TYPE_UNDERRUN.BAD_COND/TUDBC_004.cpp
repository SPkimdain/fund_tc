/* TUDBC_004 - Check boundary value. */
struct TUDBC_004_Struct {
  int idx;
  char buf[10];
};

void TUDBC_004_function(TUDBC_004_Struct& obj) {
  if(obj.idx < 1) {
    // [min, 0]
    obj.buf[obj.idx] = 10; //It's ok. 
  }

  if(obj.idx >= -1) {
    // [-1, max]
    obj.buf[obj.idx] = 15; //@violation TYPE_UNDERRUN.BAD_COND
  }
}
