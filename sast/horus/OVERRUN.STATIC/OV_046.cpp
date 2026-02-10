
/* OV_046 - buffer_overrun_03_04 from opus */
struct OV_046_Struct {
  int i;
  char c;
  long l;
  char *buf;
};

int OV_046_function1(OV_046_Struct *ptr, int size){
  ptr->buf[size] = 0; 
  return 0;
}

int OV_046_function2() {
  int i;
  OV_046_Struct sb;
  char buf[256];
  sb.buf = buf;

  for(i = 0; i < 256; i++)
    sb.buf[i] = 'a';

  i++;
  OV_046_function1(&sb, i); //@violation OVERRUN.STATIC
  return 0;
}
