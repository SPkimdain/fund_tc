
/* UDD_053 - deep fiedls */
struct UDD_053_Struct1 {
  char flag;
  int index;
};

struct UDD_053_Struct2 {
  UDD_053_Struct1 ovObj1;
};

struct UDD_053_Struct3{
  UDD_053_Struct2 ovObj2;
};

void UDD_053_function(int flag) {
  int* arr = new int[10];
  if(arr == 0) {
    return;
  }

  UDD_053_Struct3 obj;
  if(flag > 10) {
    obj.ovObj2.ovObj1.index = 5;
  }
  else {
    obj.ovObj2.ovObj1.index = -1;
  }

  arr[obj.ovObj2.ovObj1.index] = 1234; //@violation UNDERRUN.DYNAMIC

  delete[] arr;
}
