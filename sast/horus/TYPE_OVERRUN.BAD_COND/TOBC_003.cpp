/* Check upper bound. */
struct TOBC_003_Struct {
  int idx;
  char buf[10];
};

void TOBC_003_function(TOBC_003_Struct& obj) {
  if(obj.idx >= 9) {
    // [9, max]
    obj.buf[obj.idx] = 10; //It's ok. 
  }

  if(obj.idx >= 6 && obj.idx < 12) {
    // [6, 11]
    obj.buf[obj.idx] = 15; //@violation TYPE_OVERRUN.BAD_COND

    obj.buf[obj.idx] = 20; //Ignore. second bad cond.

    obj.buf[obj.idx] = 30; //Ignore. third bad cond.
  }

}
