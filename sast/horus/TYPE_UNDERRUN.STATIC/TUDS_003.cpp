
/* TUDS_003 - Access field  */
struct TUDS_003_Struct {
  int value[5];
};

void TUDS_003_function(int arg) {
  TUDS_003_Struct ndStruct;  
  ndStruct.value[-1] = 10; //@violation TYPE_UNDERRUN.STATIC
}
