
/* TOS_007 - buffer_overrun_02_04 from opus */
struct TOS_007_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TOS_007_function1(TOS_007_Struct *ptr, int size){
  ptr->buf[size] = 0;
  return 0;
}

int TOS_007_function2(){
  int i;
  TOS_007_Struct sb;

  for(i = 0; i<256; i++)
    sb.buf[i] = 'a';

  TOS_007_function1(&sb, i); //@violation TYPE_OVERRUN.STATIC
  return 0;
}
