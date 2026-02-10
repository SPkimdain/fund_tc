
/* DBZ_010 - Complex expression */
void DBZ_010_function() {
  int value = 10;
  int value2 = 5;
  int value3 = -1;
  int *ptr = &value3;
  int *ptr2 = &value;
  int *ptr3 = &value2;

  int ret = 0;

  ret = *ptr3 +  //No problem.
    *ptr3 -
    *ptr2;

  ret = *ptr3 +
    (*ptr2 / (*ptr + 1)); //@violation DIV_BY_ZERO
}
