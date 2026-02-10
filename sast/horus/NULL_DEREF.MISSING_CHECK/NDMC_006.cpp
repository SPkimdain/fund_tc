
/* NDMC_006 - Access field  */
struct NDMC_006_Struct {
  int value;
  int* value2;
};

int NDMC_006_function(int arg, NDMC_006_Struct& ndStruct) {
  int ret = 0;
  
  ndStruct.value = 10;
  if(ndStruct.value2 != 0) {
    ret += *ndStruct.value2;
  }

  
  ret += *ndStruct.value2; //@violation NULL_DEREF.MISSING_CHECK

  return ret;
}
