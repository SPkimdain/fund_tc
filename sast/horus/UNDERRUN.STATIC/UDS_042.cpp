
/* UDS_042 - buffer_overrun_03_01 from opus */
struct UDS_042_Struct {
  int i;
  char c;
  long l;
  char *buf;
};


int UDS_042_function1(UDS_042_Struct *ptr, int size){
  ptr->buf[size] = 0;  
  return 0;
}

int UDS_042_function2(){
  UDS_042_Struct sb;
  char buf[256];
  sb.buf = buf;

  UDS_042_function1(&sb, -1); //@violation UNDERRUN.STATIC

  return 0;
}
