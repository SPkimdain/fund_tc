
/* ND_053 - deep fiedls */
struct ND_053_Struct1 {
  char flag;
  int* value;
};

struct ND_053_Struct2 {
  ND_053_Struct1 ndObj1;
};

struct ND_053_Struct3{
  ND_053_Struct2 ndObj2;
};

void ND_053_function(int flag, ND_053_Struct3& obj, int& v) {
  if(flag > 10) {
    if(obj.ndObj2.ndObj1.value != 0) {
      *obj.ndObj2.ndObj1.value = 1024;
    }
  }
  else {
    obj.ndObj2.ndObj1.value = &v;
  }

  *obj.ndObj2.ndObj1.value = 10; //@violation NULL_DEREF.MISSING_CHECK
}

