

/* TOS_009 - buffer_overrun_02_02 from opus */
struct TOS_009_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TOS_009_function1(TOS_009_Struct *ptr, int size){
  ptr->buf[size] = 0;  
  return 0;
}

void TOS_009_function2(TOS_009_Struct *ptr, int size){
  int i;
  TOS_009_Struct *p;
  i = size;
  p = ptr;
  TOS_009_function1(p, i);
}
void TOS_009_function3(TOS_009_Struct *ptr, int size){
  int i;
  TOS_009_Struct *p;
  i = size;
  p = ptr;
  TOS_009_function2(p, i);
}

void TOS_009_function4(TOS_009_Struct *ptr, int size){
  int i;
  TOS_009_Struct *p;
  i = size;
  p = ptr;
  TOS_009_function3(p, i);
}

int TOS_009_function5(){
  TOS_009_Struct sb;

  TOS_009_function4(&sb, 256); //@violation TYPE_OVERRUN.STATIC

  return 0;
}
