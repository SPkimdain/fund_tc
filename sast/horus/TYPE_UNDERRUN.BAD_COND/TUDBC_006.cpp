
/* TUDBC_006 - if branch */
struct TUDBC_006_Struct {
  int value[4];
};

void TUDBC_006_function(int arg, int index) {
  TUDBC_006_Struct obj;
  int* ptr = 0;

  if(index >= -1) {
    if(arg == 10) {
      ptr = (obj.value + 1);
    }
    else {
      ptr = (obj.value + index);
    }

    *ptr = 10; //@violation TYPE_UNDERRUN.BAD_COND
  }
}
