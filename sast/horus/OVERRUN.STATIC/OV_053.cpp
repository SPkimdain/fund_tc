
/* OV_053 - deep fiedls */
struct OV_053_Struct1 {
  char flag;
  int index;
};

struct OV_053_Struct2 {
  OV_053_Struct1 ovObj1;
};

struct OV_053_Struct3{
  OV_053_Struct2 ovObj2;
};

void OV_053_function(int flag) {
  int arr[10] = { 0, };
  OV_053_Struct3 obj;
  if(flag > 10) {
    obj.ovObj2.ovObj1.index = 5;
  }
  else {
    obj.ovObj2.ovObj1.index = 10;
  }

  arr[obj.ovObj2.ovObj1.index] = 1234; //@violation OVERRUN.STATIC
}
