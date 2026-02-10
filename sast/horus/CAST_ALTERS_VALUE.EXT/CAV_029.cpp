
/* CAV_029 - hexadecimal */

enum CAV_029_Enum {
  EXTRET_FALSE = 0xffffffe0,
  EXTRET_TRUE = 0xffffffe1,
  EXTRET_VALUE_FALSE = 0xffffffe2,
  EXTRET_VALUE_TRUE = 0xffffffe3,
  EXTRET_DEFAULT = 0xfffffff0,
  EXTRET_BYPASS = 0xfffffff1,
  EXTRET_BLOCK = 0xfffffff2,
};

void CAV_029_function1(int flag, int level){
  unsigned long value = 0;

  if(flag > 50) {
    value = EXTRET_FALSE; //It's ok.
  }
  else if(flag > 10) {
    value = 0x0123; //It's ok.
  }
  else {
    value = -20; //@violation CAST_ALTERS_VALUE.EXT
  }
}
