
/* DBZ_006 - Access field  */
struct DBZ_006_Struct {
  int value;
  int value2;
};

void DBZ_006_function(int arg) {
  DBZ_006_Struct ndStruct;
  ndStruct.value = 10;
  ndStruct.value2 = 0;
  
  int ret = 0;
  ret = 1000 / ndStruct.value; //It's ok.
  ret = 10000 / ndStruct.value2; //@violation DIV_BY_ZERO
}
