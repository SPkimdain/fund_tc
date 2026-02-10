
/* OV_042 - buffer_overrun_03_01 from opus */
struct OV_042_Struct {
  int i;
  char c;
  long l;
  char *buf;
};


int OV_042_function1(OV_042_Struct *ptr, int size){
  ptr->buf[size] = 0;  
  return 0;
}

int OV_042_function2(){
  OV_042_Struct sb;
  char buf[256];
  sb.buf = buf;

  OV_042_function1(&sb, 256); //@violation OVERRUN.STATIC

  return 0;
}
