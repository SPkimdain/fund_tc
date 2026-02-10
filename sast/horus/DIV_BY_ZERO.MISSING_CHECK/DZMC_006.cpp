
/* DZMC_006 - Access field  */
struct DZMC_006_Struct {
  int value;
  int value2;
};

int DZMC_006_function(int arg, DZMC_006_Struct& ndStruct) {
  int retVal = 0;
  ndStruct.value = 10;
  
  if(ndStruct.value2 != 0) {
    retVal++;
  }

  int ret = 0;
  ret = 1000 / ndStruct.value; //It's ok.
  
  ret = 10000 / ndStruct.value2; //@violation DIV_BY_ZERO.MISSING_CHECK

  return retVal;
}
