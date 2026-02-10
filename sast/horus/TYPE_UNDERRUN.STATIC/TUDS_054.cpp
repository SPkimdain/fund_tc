
/* TUDS_054 - boundary index */
struct TUDS_054_Struct{
  int a[10];
};


void TUDS_054_function(int value) {
  TUDS_054_Struct obj;
  if(value < 0) { //Wrong check.
    obj.a[value] = 10; //@violation TYPE_UNDERRUN.STATIC
  }
}

