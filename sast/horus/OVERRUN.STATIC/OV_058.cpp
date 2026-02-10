
/* OV_058 - different type witdh */
struct OV_058_Struct {
  unsigned char* idx;
};

int OV_058_function1(OV_058_Struct& obj) {
  int i = 0;
  int arr[256] = { 0, };
  int ret = 0;
  i = *(obj.idx);
  if(i == 255) {
    ret += arr[i];
  }
  
  return ret;
}

 void OV_058_function2(int value) {
   int arr[10] = { 0, };
   if(value > 10) { //Wrong check.
     arr[value] = 10; //@violation OVERRUN.STATIC
   }
 }

