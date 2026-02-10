


/* UN_010 - Complex expression */
void UN_010_function() {
  int value1 = 10;
  int value2 = 5;
  int value3;
  int *ptr1 = &value1;
  int *ptr2 = &value2;
  int *ptr3 = &value3;

  int ret = 0;

  ret = *ptr1 +  //No problem.
    *ptr1 -
    *ptr2;

  ret = *ptr1 +
    *ptr2 -
    (*ptr3 + 1); //@violation UNINIT

}
