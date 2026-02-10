

/* TUDS_043 - buffer_overrun_03_02 from opus */
struct TUDS_043_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TUDS_043_function1(TUDS_043_Struct *ptr, int size){
  ptr->buf[size] = 0;   
  return 0;
}

void TUDS_043_function2(TUDS_043_Struct *ptr, int size){
  TUDS_043_function1(ptr, size);
}
void TUDS_043_function3(TUDS_043_Struct *ptr, int size){
  TUDS_043_function2(ptr, size);
}
void TUDS_043_function4(TUDS_043_Struct *ptr, int size){
  TUDS_043_function3(ptr, size);
}
void TUDS_043_function5(TUDS_043_Struct *ptr, int size){
  TUDS_043_function4(ptr, size);
}
int TUDS_043_function6(){
  TUDS_043_Struct sb;

  TUDS_043_function5(&sb, -1);//@violation TYPE_UNDERRUN.STATIC

  return 0;
}
