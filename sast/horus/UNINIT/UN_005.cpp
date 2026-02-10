

/* UN_005 - switch branch */
void UN_005_function(int flag) {
  int a;
  int b;

  switch(flag) {
  case 0:
  case 1:
  case 2:
  case 3:
    a = 10;
    break;
  default:
    b = 1;
    break;
  }

  b = a; //@violation UNINIT
}
