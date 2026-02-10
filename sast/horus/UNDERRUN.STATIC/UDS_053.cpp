
/* UDS_053 - deep fiedls */
struct UDS_053_Struct1 {
  char flag;
  int index;
};

struct UDS_053_Struct2 {
  UDS_053_Struct1 ovObj1;
};

struct UDS_053_Struct3{
  UDS_053_Struct2 ovObj2;
};

void UDS_053_function(int flag) {
  int arr[10] = { 0, };
  UDS_053_Struct3 obj;
  if(flag > 10) {
    obj.ovObj2.ovObj1.index = 5;
  }
  else {
    obj.ovObj2.ovObj1.index = -1;
  }

  arr[obj.ovObj2.ovObj1.index] = 1234; //@violation UNDERRUN.STATIC
}
