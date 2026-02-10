#include <new>

/* OD_047 - buffer_overrun_03_05 from opus */
struct OD_047_Struct {
  int i;
  char c;
  long l;
  char *buf;
};

int OD_047_function1(int i){

  if(i == 0)
    return 1;
  else
    return 1000;
}

int OD_047_function2(int flg){
  int i;
  OD_047_Struct sb;
  char* buf = new char[256];
  if(buf == 0) {
    return 0;
  }
  sb.buf = buf;

  i = OD_047_function1(flg);

  sb.buf[i] = 'a'; //@violation OVERRUN.DYNAMIC

  delete[] buf;

  return 0;
}
