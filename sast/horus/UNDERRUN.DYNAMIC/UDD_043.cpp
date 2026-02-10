

/* UDD_043 - buffer_overrun_03_02 from opus */
struct UDD_043_Struct {
  int i;
  char c;
  long l;
  char *buf;
};

int UDD_043_function1(UDD_043_Struct *ptr, int size){
  ptr->buf[size] = 0;   
  return 0;
}

void UDD_043_function2(UDD_043_Struct *ptr, int size){
  UDD_043_function1(ptr, size);
}
void UDD_043_function3(UDD_043_Struct *ptr, int size){
  UDD_043_function2(ptr, size);
}
void UDD_043_function4(UDD_043_Struct *ptr, int size){
  UDD_043_function3(ptr, size);
}
void UDD_043_function5(UDD_043_Struct *ptr, int size){
  UDD_043_function4(ptr, size);
}
int UDD_043_function6(){
  UDD_043_Struct sb;
  char* buf = new char[256];
  if(buf == 0) {
    return 0;
  }
  sb.buf = buf;

  UDD_043_function5(&sb, -1);//@violation UNDERRUN.DYNAMIC

  delete[] buf;
  return 0;
}
