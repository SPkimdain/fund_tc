
/* TOS_042 - buffer_overrun_03_01 from opus */
struct TOS_042_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};


int TOS_042_function1(TOS_042_Struct *ptr, int size){
  ptr->buf[size] = 0;  
  return 0;
}

int TOS_042_function2(){
  TOS_042_Struct sb;

  TOS_042_function1(&sb, 256); //@violation TYPE_OVERRUN.STATIC

  return 0;
}
