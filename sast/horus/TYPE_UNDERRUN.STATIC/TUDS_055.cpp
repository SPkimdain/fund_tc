/* TUDS_056 - trace loop counter */

struct TUDS_055_Struct{
  int a[100];
};

void TUDS_055_function1(int index){
  TUDS_055_Struct tos;
  tos.a[index] = 20;
}

void TUDS_055_function2(){
  int i = 0;
  int ret = 0;
  for(i = 100; i >= 0; i--) {
    ret++;
  }

  TUDS_055_function1(i);   //@violation TYPE_UNDERRUN.STATIC
}
