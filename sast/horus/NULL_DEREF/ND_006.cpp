
/* ND_006 - Access field  */
struct ND_006_Struct {
  int value;
  int* value2;
};

void ND_006_function(int arg) {
  ND_006_Struct ndStruct;
  ndStruct.value = 10;
  ndStruct.value2 = 0;
  
  *ndStruct.value2 = 10; //@violation NULL_DEREF
}
