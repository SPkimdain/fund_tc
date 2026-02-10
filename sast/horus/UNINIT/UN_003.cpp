#pragma warning(disable : 4700)

/* UN_003 - if branch1 */
void UN_003_function(int flag) {
  int a;
  int b;

  if(flag > 0) {
    a = 10;
    b = a;
  }
  else {
    b = 10;
    b = a; //@violation UNINIT
  }

}
