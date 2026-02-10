
/* OD_042 - buffer_overrun_03_01 from opus */
struct OD_042_Struct {
  int i;
  char c;
  long l;
  char *buf;
};


int OD_042_function1(OD_042_Struct *ptr, int size){
  ptr->buf[size] = 0;  
  return 0;
}

int OD_042_function2(){
  OD_042_Struct sb;
  char* buf = new char[256];
  if(buf == 0) {
    return 0;
  }
  sb.buf = buf;

  OD_042_function1(&sb, 256); //@violation OVERRUN.DYNAMIC

  delete[] buf;

  return 0;
}
