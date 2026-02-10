
/* TUDS_008 - buffer_overrun_02_01 from opus */
struct TUDS_008_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};

int TUDS_008_function1(TUDS_008_Struct *ptr, int size){
  ptr->buf[size] = 0; 
  return 0;
}

int TUDS_008_function2(){
  int i;
  TUDS_008_Struct sb;

  TUDS_008_function1(&sb, -1); //@violation TYPE_UNDERRUN.STATIC

  return 0;
}
