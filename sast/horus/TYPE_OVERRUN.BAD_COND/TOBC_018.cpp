
/* TOBC_018 - reminder */

struct TOBC_018_Struct1 {
  char hex[15];
  int index;
};

void TOBC_018_function1(int attr) {
  TOBC_018_Struct1 obj;
  if(attr >= 22 && attr <= 31) { /* [22, 31] [33, 34] */
    attr = attr % 15; /* [0, 1], [7, 14] */
    obj.hex[attr] = 'x'; //It's ok.
  }
}


void TOBC_018_function2(int idx) {
  TOBC_018_Struct1 obj;

  if(idx >= 0 && idx <= 20) {
    obj.hex[idx] = 10;             //@violation TYPE_OVERRUN.BAD_COND
  }
}
