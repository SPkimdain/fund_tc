#include <new>

/* OV_047 - buffer_overrun_03_05 from opus */
struct OV_047_Struct {
  int i;
  char c;
  long l;
  char *buf;
};

int OV_047_function1(int i){

  if(i == 0)
    return 1;
  else
    return 1000;
}

int OV_047_function2(int flg){
  int i;
  OV_047_Struct sb;
  char buf[256];
  sb.buf = buf;

  i = OV_047_function1(flg);

  sb.buf[i] = 'a'; //@violation OVERRUN.STATIC

  return 0;
}
