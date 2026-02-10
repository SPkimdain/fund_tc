#include <new>

/* TOS_047 - buffer_overrun_03_05 from opus */
struct TOS_047_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TOS_047_function1(int i){

  if(i == 0)
    return 1;
  else
    return 1000;
}

int TOS_047_function2(int flg){
  int i;
  TOS_047_Struct sb;

  i = TOS_047_function1(flg);

  sb.buf[i] = 'a'; //@violation TYPE_OVERRUN.STATIC

  return 0;
}
