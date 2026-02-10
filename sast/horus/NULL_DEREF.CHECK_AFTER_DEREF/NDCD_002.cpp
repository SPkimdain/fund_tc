//@checker NULL_DEREF.CHECK_AFTER_DEREF
/* NDCD_002 - field null dereference. */
struct NDCD_002_Struct {
  int value;
  int value2;
};

int NDCD_002_function(NDCD_002_Struct* obj, int* p) {
  int ret = 0;
  
  int x = obj->value2;
  
  int* data = &(obj->value);

  if(data != 0) { //It's ok.
    ret++;
  }

  if(obj){ //@violation NULL_DEREF.CHECK_AFTER_DEREF
    ret--;
  }
  return 0;
}

