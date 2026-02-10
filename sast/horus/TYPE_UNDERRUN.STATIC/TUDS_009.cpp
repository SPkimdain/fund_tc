

/* TUDS_009 - buffer_overrun_02_02 from opus */
struct TUDS_009_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TUDS_009_function1(TUDS_009_Struct *ptr, int size){
  ptr->buf[size] = 0;  
  return 0;
}

void TUDS_009_function2(TUDS_009_Struct *ptr, int size){
  int i;
  TUDS_009_Struct *p;
  i = size;
  p = ptr;
  TUDS_009_function1(p, i);
}
void TUDS_009_function3(TUDS_009_Struct *ptr, int size){
  int i;
  TUDS_009_Struct *p;
  i = size;
  p = ptr;
  TUDS_009_function2(p, i);
}

void TUDS_009_function4(TUDS_009_Struct *ptr, int size){
  int i;
  TUDS_009_Struct *p;
  i = size;
  p = ptr;
  TUDS_009_function3(p, i);
}

int TUDS_009_function5(){
  TUDS_009_Struct sb;

  TUDS_009_function4(&sb, -2); //@violation TYPE_UNDERRUN.STATIC

  return 0;
}
