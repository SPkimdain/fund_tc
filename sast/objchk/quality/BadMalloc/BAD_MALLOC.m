void test(int c) {

  
  
  int *p = malloc(1);


   p = malloc(sizeof(char));
  p = p - 1;
  free(p); //@violation
  //argument to free() is offset by -4 bytes
}
