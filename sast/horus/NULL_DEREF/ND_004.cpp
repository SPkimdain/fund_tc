
/* ND_004 - if branch2 */
void ND_004_function(int arg) {
  int value = 10;
  int* ptr1 = 0;
  int* ptr2 = 0;
  if(arg == 10) {
    ptr1 = &value;
  }
  else {
    ptr1 = ptr2;
  }

  *ptr1 = 10; //@violation NULL_DEREF
}
