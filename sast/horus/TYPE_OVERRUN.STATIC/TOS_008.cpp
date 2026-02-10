
/* TOS_008 - buffer_overrun_02_01 from opus */
struct TOS_008_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TOS_008_function1(TOS_008_Struct *ptr, int size){
  ptr->buf[size] = 0; 
  return 0;
}

int TOS_008_function2(){
  int i;
  TOS_008_Struct sb;

  TOS_008_function1(&sb, 256); //@violation TYPE_OVERRUN.STATIC

  return 0;
}
