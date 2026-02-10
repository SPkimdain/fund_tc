//@checker REDUNDANT_CONDITION

extern int printf ( const char * format, ... );

int foo(){
  return 1;
}
int foo2(){
  return 0;
}
void foo3(){

  int a = 0;
  int b = 1;
  int x = foo();
  int y = foo2();
  
  
  if(x==0||y==0) 
    printf("hello");



  
  if(a==0||b==0) //@violation REDUNDANT_CONDITION
    printf("hello");



  


}

