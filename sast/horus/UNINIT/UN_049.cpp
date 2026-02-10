#pragma warning(disable : 4700)

/* UN_049 - trygraphs */
void UN_049_function(int flag) {
  int value1;
  int value2 = 5;
  int p = (flag == 10) ? value1 : value2; //@violation UNINIT
}


