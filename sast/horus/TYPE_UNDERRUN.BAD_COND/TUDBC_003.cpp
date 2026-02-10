/* Check upper bound. */
struct TUDBC_003_Struct {
  int idx;
  char buf[10];
};

void TUDBC_003_function(TUDBC_003_Struct& obj) {
  if(obj.idx >= 9) {
    // [9, max]
    obj.buf[obj.idx] = 10; //It's ok. 
  }

  if(obj.idx >= -1 && obj.idx < 10) {
    // [-1, 9]
    obj.buf[obj.idx] = 15; //@violation TYPE_UNDERRUN.BAD_COND

    obj.buf[obj.idx] = 20; //Ignore. second bad cond.

    obj.buf[obj.idx] = 30; //Ignore. third bad cond.
  }

}
