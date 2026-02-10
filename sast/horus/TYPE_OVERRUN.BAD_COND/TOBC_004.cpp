/* TOBC_004 - Check boundary value. */
struct TOBC_004_Struct {
  int idx;
  char buf[10];
};

void TOBC_004_function(TOBC_004_Struct& obj) {
  if(obj.idx < 1) {
    // [min, 0]
    obj.buf[obj.idx] = 10; //It's ok. 
  }

  if(obj.idx <= 10) {
    // [min, 10]
    obj.buf[obj.idx] = 15; //@violation TYPE_OVERRUN.BAD_COND
  }
}
