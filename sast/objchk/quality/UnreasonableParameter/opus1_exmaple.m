void foo(){
  int n = -7;
  char *ch = (char*)malloc(n);  //@violation
}