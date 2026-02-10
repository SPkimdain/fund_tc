#include <new>

/* UDS_047 - buffer_overrun_03_05 from opus */
struct UDS_047_Struct {
  int i;
  char c;
  long l;
  char *buf;
};

int UDS_047_function1(int i){

  if(i == 0)
    return 1;
  else
    return -1;
}

int UDS_047_function2(int flg){
  int i;
  UDS_047_Struct sb;
  char buf[256];
  sb.buf = buf;

  i = UDS_047_function1(flg);

  sb.buf[i] = 'a'; //@violation UNDERRUN.STATIC

  return 0;
}
