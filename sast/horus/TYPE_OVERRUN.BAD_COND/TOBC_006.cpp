
/* TOBC_006 - if branch */
struct TOBC_006_Struct {
  int value[4];
};

void TOBC_006_function(int arg, int index) {
  TOBC_006_Struct obj;
  int* ptr = 0;

  if(index > 0 && index < 10) { //Wrong check.
    if(arg == 10) {
      ptr = (obj.value + 1);
    }
    else {
      ptr = (obj.value + index);
    }

    *ptr = 10; //@violation TYPE_OVERRUN.BAD_COND
  }
}
