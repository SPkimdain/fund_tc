

/* TOS_043 - buffer_overrun_03_02 from opus */
struct TOS_043_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TOS_043_function1(TOS_043_Struct *ptr, int size){
  ptr->buf[size] = 0;   
  return 0;
}

void TOS_043_function2(TOS_043_Struct *ptr, int size){
  TOS_043_function1(ptr, size);
}
void TOS_043_function3(TOS_043_Struct *ptr, int size){
  TOS_043_function2(ptr, size);
}
void TOS_043_function4(TOS_043_Struct *ptr, int size){
  TOS_043_function3(ptr, size);
}
void TOS_043_function5(TOS_043_Struct *ptr, int size){
  TOS_043_function4(ptr, size);
}
int TOS_043_function6(){
  TOS_043_Struct sb;

  TOS_043_function5(&sb, 256);//@violation TYPE_OVERRUN.STATIC

  return 0;
}
