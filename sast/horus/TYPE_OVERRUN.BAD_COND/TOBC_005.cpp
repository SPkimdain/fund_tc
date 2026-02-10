
/* TOBC_005 - switch branch  */
struct TOBC_005_Struct {
  int value[4];
};

void TOBC_005_function(int arg, unsigned int index) {
  TOBC_005_Struct v;
  int* ptr = 0;
  if(index < 6) { //Wrong check.
    switch(arg) {
    case 0:
    case 1:
    case 2:
      ptr = (v.value + 1);
      break;
    case 3:
      ptr = (v.value + index);
      break;
    default:
      ptr = v.value;
      break;
    }
    *ptr = 10; //@violation TYPE_OVERRUN.BAD_COND
  }
}
