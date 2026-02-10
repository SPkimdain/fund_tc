//@checker IGNORED_RETURN_VALUE
extern int scanf ( const char * format, ... );

int IGV_001_function1 (){
  int ret = 0;
  int c;
  scanf("%d", &c); //@violation IGNORED_RETURN_VALUE
  
  int x = scanf("%d", &c); //It's ok.
  
  if(scanf("%d", &c) != 0) { //It's ok.
    ret++;
  }
  
  return ret;
}
