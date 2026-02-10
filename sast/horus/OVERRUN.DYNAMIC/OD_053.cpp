
/* OD_053 - deep fiedls */
struct OD_053_Struct1 {
  char flag;
  int index;
};

struct OD_053_Struct2 {
  OD_053_Struct1 ovObj1;
};

struct OD_053_Struct3{
  OD_053_Struct2 ovObj2;
};

void OD_053_function(int flag) {
  int* arr = new int[10];
  if(arr == 0) {
    return;
  }

  OD_053_Struct3 obj;
  if(flag > 10) {
    obj.ovObj2.ovObj1.index = 5;
  }
  else {
    obj.ovObj2.ovObj1.index = 10;
  }

  arr[obj.ovObj2.ovObj1.index] = 1234; //@violation OVERRUN.DYNAMIC

  delete[] arr;
}
