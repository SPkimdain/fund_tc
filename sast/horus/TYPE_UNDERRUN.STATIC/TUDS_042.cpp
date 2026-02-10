
/* TUDS_042 - buffer_overrun_03_01 from opus */
struct TUDS_042_Struct {
  int i;
  char c;
  long l;
  char buf[256];
};


int TUDS_042_function1(TUDS_042_Struct *ptr, int size){
  ptr->buf[size] = 0;  
  return 0;
}

int TUDS_042_function2(){
  TUDS_042_Struct sb;

  TUDS_042_function1(&sb, -256); //@violation TYPE_UNDERRUN.STATIC

  return 0;
}
