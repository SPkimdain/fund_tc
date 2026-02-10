

/* UDS_043 - buffer_overrun_03_02 from opus */
struct UDS_043_Struct {
  int i;
  char c;
  long l;
  char *buf;
};

int UDS_043_function1(UDS_043_Struct *ptr, int size){
  ptr->buf[size] = 0;   
  return 0;
}

void UDS_043_function2(UDS_043_Struct *ptr, int size){
  UDS_043_function1(ptr, size);
}
void UDS_043_function3(UDS_043_Struct *ptr, int size){
  UDS_043_function2(ptr, size);
}
void UDS_043_function4(UDS_043_Struct *ptr, int size){
  UDS_043_function3(ptr, size);
}
void UDS_043_function5(UDS_043_Struct *ptr, int size){
  UDS_043_function4(ptr, size);
}
int UDS_043_function6(){
  UDS_043_Struct sb;
  char buf[256];
  sb.buf = buf;

  UDS_043_function5(&sb, -1);//@violation UNDERRUN.STATIC

  return 0;
}
