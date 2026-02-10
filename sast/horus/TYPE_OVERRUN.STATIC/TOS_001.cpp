struct TOS_001_Struct{
  int a[100];
};

void TOS_001_function1(int index){
  TOS_001_Struct tos;
  tos.a[index + 5] = 20;
}
 
 void TOS_001_function2(){
  TOS_001_function1(98);   //@violation TYPE_OVERRUN.STATIC
}
