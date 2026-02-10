
/* OD_058 - different type witdh */
struct OD_058_Struct {
  unsigned char* idx;
};

int OD_058_function1(OD_058_Struct& obj) {
  int i = 0;
  int* arr = new int[256];
  arr[255] = 10;
  int ret = 0;
  i = *(obj.idx);
  if(i == 255) {
    ret += arr[i];
  }
  
  delete[] arr;
  
  return ret;
}

 void OD_058_function2(int value) {
  int* arr = new int[10];
  if(value > 10) { //Wrong check.
    arr[value] = 10; //@violation OVERRUN.DYNAMIC
  }

  delete[] arr;
 }

