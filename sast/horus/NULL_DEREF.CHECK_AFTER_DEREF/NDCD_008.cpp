
/* NDCD_008 - deep fiedls */
struct NDCD_008_Struct1 {
  char flag;
  int* value;
  int* value2;
};

struct NDCD_008_Struct2 {
  NDCD_008_Struct1 ndObj1;
};

struct NDCD_008_Struct3{
  NDCD_008_Struct2 ndObj2;
};

void NDCD_008_function(int flag, NDCD_008_Struct3& obj) {
  int v = 1000;

  if(flag > 10) {
    *obj.ndObj2.ndObj1.value = 10;
  }
  else {
    if(obj.ndObj2.ndObj1.value2 != 0) {
      *obj.ndObj2.ndObj1.value2 = 30;
      
      return;
    }
  }
  
  if(obj.ndObj2.ndObj1.value2 != 0) {
    v += *obj.ndObj2.ndObj1.value2;
  }

  if(obj.ndObj2.ndObj1.value != 0) { //@violation NULL_DEREF.CHECK_AFTER_DEREF
    v += *obj.ndObj2.ndObj1.value;
  }

}

