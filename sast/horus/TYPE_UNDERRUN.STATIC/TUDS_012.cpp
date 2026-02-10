#include <memory.h>

/* TUDS_012 - buffer_overrun_02_05 from opus */
struct TUDS_012_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TUDS_012_function1(int i){

  if(i == 0)
    return 1;
  else
    return -1;
}

int TUDS_012_function2(int flg){
  int i;
  TUDS_012_Struct sb;

  i = TUDS_012_function1(flg);

  sb.buf[i] = 'a'; //@violation TYPE_UNDERRUN.STATIC

  return 0;
}
