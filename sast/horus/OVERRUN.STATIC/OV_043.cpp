

/* OV_043 - buffer_overrun_03_02 from opus */
struct OV_043_Struct {
  int i;
  char c;
  long l;
  char *buf;
};

int OV_043_function1(OV_043_Struct *ptr, int size){
  ptr->buf[size] = 0;   
  return 0;
}

void OV_043_function2(OV_043_Struct *ptr, int size){
  OV_043_function1(ptr, size);
}
void OV_043_function3(OV_043_Struct *ptr, int size){
  OV_043_function2(ptr, size);
}
void OV_043_function4(OV_043_Struct *ptr, int size){
  OV_043_function3(ptr, size);
}
void OV_043_function5(OV_043_Struct *ptr, int size){
  OV_043_function4(ptr, size);
}
int OV_043_function6(){
  OV_043_Struct sb;
  char buf[256];
  sb.buf = buf;

  OV_043_function5(&sb, 256);//@violation OVERRUN.STATIC

  return 0;
}
