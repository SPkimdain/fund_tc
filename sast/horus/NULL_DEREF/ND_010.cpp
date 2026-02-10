


/* ND_010 - Complex expression */
void ND_010_function() {
  int value = 10;
  int value2 = 5;
  int *ptr = 0;
  int *ptr2 = &value;
  int *ptr3 = &value2;

  int ret = 0;

  ret = *ptr3 +  //No problem.
    *ptr3 -
    *ptr2;

  ret = *ptr3 +
    *ptr2 -
    (*ptr + 1); //@violation NULL_DEREF

}
