

/* OD_043 - buffer_overrun_03_02 from opus */
struct OD_043_Struct {
  int i;
  char c;
  long l;
  char *buf;
};

int OD_043_function1(OD_043_Struct *ptr, int size){
  ptr->buf[size] = 0;   
  return 0;
}

void OD_043_function2(OD_043_Struct *ptr, int size){
  OD_043_function1(ptr, size);
}
void OD_043_function3(OD_043_Struct *ptr, int size){
  OD_043_function2(ptr, size);
}
void OD_043_function4(OD_043_Struct *ptr, int size){
  OD_043_function3(ptr, size);
}
void OD_043_function5(OD_043_Struct *ptr, int size){
  OD_043_function4(ptr, size);
}
int OD_043_function6(){
  OD_043_Struct sb;
  char* buf = new char[256];
  if(buf == 0) {
    return 0;
  }
  sb.buf = buf;

  OD_043_function5(&sb, 256);//@violation OVERRUN.DYNAMIC

  delete[] buf;
  return 0;
}
