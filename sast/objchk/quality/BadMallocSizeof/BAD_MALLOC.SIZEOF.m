 void test() {

 	char file[1024];
  long *p = malloc(sizeof(short)); //@violation
    //result is converted to 'long *', which is
    // incompatible with operand type 'short'
  free(p);
}