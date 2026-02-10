//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_006 - Access field  */
struct NDCD_006_Struct {
  int value;
  int* value2;
};

int NDCD_006_function(int arg, NDCD_006_Struct& ndStruct) {
  ndStruct.value = 10;
  *ndStruct.value2 = 50;

  if(ndStruct.value2) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
    return 0;
  }
  else {
    return 1;
  }

}
