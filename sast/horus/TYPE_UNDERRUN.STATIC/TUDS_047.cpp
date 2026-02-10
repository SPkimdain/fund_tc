#include <new>

/* TUDS_047 - buffer_overrun_03_05 from opus */
struct TUDS_047_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TUDS_047_function1(int i){

  if(i == 0)
    return 1;
  else
    return -1;
}

int TUDS_047_function2(int flg){
  int i;
  TUDS_047_Struct sb;

  i = TUDS_047_function1(flg);

  sb.buf[i] = 'a'; //@violation TYPE_UNDERRUN.STATIC

  return 0;
}
