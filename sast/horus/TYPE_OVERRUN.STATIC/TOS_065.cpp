/* TOS_065 - trace loop counter */

struct TOS_065_Struct{
  int a[100];
};

void TOS_065_function1(int index){
  TOS_065_Struct tos;
  tos.a[index + 5] = 20;
}

int TOS_065_function2(){
  int ret = 0;
  int index;
  for(index = 0; index != 98; index++) {
    ret += 2;
  }

  TOS_065_function1(index);   //@violation TYPE_OVERRUN.STATIC

  return ret;
}


