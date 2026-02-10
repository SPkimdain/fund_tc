
/* TOS_058 - different type witdh  */
struct TOS_058_Struct {
  unsigned char* idx;
  int a[10];
  int arr[256];
};

int TOS_058_function1(TOS_058_Struct& obj) {
  int i = 0;
  int ret = 0;
  i = *(obj.idx);
  if(i == 255) {
    ret += obj.arr[i]; //It's ok.
  }
  
  return ret;
}


void TOS_058_function2(int value) {
  TOS_058_Struct obj;
  if(value > 10) { //Wrong check.
    obj.a[value] = 10; //@violation TYPE_OVERRUN.STATIC
  }
}

