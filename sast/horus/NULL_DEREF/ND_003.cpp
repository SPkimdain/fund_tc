
/* ND_003 - if branch1 */
void ND_003_function(int arg) {
  int value = 10;
  int* ptr = &value;
  if(arg == 10) {
    *ptr = 50;
  }
  else {
    ptr = 0;
    *ptr = 10; //@violation NULL_DEREF
  }
  
}
