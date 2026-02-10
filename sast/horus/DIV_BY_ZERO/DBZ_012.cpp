
/* DBZ_012 - for */
void DBZ_012_function() {
  int value = 0;
  int arg = 0;
  for(int i = 0; i < 10; i++) {
    value++;
  }

  int ret = 1000 / arg; //@violation DIV_BY_ZERO

}

