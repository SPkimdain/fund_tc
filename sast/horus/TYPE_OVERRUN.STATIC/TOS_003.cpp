
/* TOS_003 - Access field  */
struct TOS_003_Struct {
  int value[5];
};

void TOS_003_function(int arg) {
  TOS_003_Struct ndStruct;  
  ndStruct.value[6] = 10; //@violation TYPE_OVERRUN.STATIC
}
