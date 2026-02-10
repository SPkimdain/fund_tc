
/* UN_004 - if branch2 */
void UN_004_function(int flag) {
  int a;
  int b;

  if(flag > 0) {
    a = 10;
  }
  else {
    b = 10;
  }

  b = a; //@violation UNINIT
}
