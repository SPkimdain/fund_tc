
/* IU_004 - Access field  */
struct IU_004_Struct {
  int value;
  int value2;
};

void IU_004_function(int arg) {
  IU_004_Struct ndStruct;
  ndStruct.value = -2147483647;
  ndStruct.value2 = 2;
  
  int ret = 0;
  ret = ndStruct.value + ndStruct.value2; //It's ok.
  ret = ndStruct.value - ndStruct.value2; //@violation INTEGER_UNDERFLOW
}
