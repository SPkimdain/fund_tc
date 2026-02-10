struct TUDS_001_Struct{
  int a[100];
};

void TUDS_001_function1(int index){
  TUDS_001_Struct tos;
  tos.a[index + 5] = 20;
}
 
 void TUDS_001_function2(){
  TUDS_001_function1(-6);   //@violation TYPE_UNDERRUN.STATIC
}
