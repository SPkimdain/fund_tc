
/* DBZ_053 - deep fiedls */
struct DBZ_053_Struct1 {
  char flag;
  int value;
};

struct DBZ_053_Struct2 {
  DBZ_053_Struct1 ndObj1;
};

struct DBZ_053_Struct3{
  DBZ_053_Struct2 ndObj2;
};

int DBZ_053_function(int flag) {
  int v = 1053;
  DBZ_053_Struct3 obj;
  if(flag > 10) {
    obj.ndObj2.ndObj1.value = 1000; //This flow is a problem.
  }
  else {
    obj.ndObj2.ndObj1.value = v;
  }

  return 1000 / (obj.ndObj2.ndObj1.value % 10); //@violation DIV_BY_ZERO
}

