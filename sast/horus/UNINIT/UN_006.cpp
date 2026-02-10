
/* UN_006 - Access field  */
struct UN_006_Struct {
  int value;
  int value2;
};

void UN_006_function(int arg) {
  UN_006_Struct ndStruct;
  ndStruct.value = 10;
  int x = 0;
  
  int ret1 = ndStruct.value; //It's ok.
  int ret2 = ndStruct.value2; //@violation UNINIT

  
}
