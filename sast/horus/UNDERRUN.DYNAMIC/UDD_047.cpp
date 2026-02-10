#include <new>

/* UDD_047 - buffer_overrun_03_05 from opus */
struct UDD_047_Struct {
  int i;
  char c;
  long l;
  char *buf;
};

int UDD_047_function1(int i){

  if(i == 0)
    return 1;
  else
    return -1;
}

int UDD_047_function2(int flg){
  int i;
  UDD_047_Struct sb;
  char* buf = new char[256];
  if(buf == 0) {
    return 0;
  }
  sb.buf = buf;

  i = UDD_047_function1(flg);

  sb.buf[i] = 'a'; //@violation UNDERRUN.DYNAMIC

  delete[] buf;

  return 0;
}
