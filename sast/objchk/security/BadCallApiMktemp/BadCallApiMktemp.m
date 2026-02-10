void test() {
  char *x = mktemp("/tmp/zxcv"); //@violation 
 // insecure, use mkstemp
}