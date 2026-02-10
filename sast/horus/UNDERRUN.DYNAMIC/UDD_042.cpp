
/* UDD_042 - buffer_overrun_03_01 from opus */
struct UDD_042_Struct {
  int i;
  char c;
  long l;
  char *buf;
};


int UDD_042_function1(UDD_042_Struct *ptr, int size){
  ptr->buf[size] = 0;  
  return 0;
}

int UDD_042_function2(){
  UDD_042_Struct sb;
  char* buf = new char[256];
  if(buf == 0) {
    return 0;
  }
  sb.buf = buf;

  UDD_042_function1(&sb, -1); //@violation UNDERRUN.DYNAMIC

  delete[] buf;

  return 0;
}
