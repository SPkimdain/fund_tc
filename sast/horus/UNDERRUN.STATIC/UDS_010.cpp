
/* UDS_010 - Complex expression */
void UDS_010_function() {
  int value[5] = { 1, };
  int *ptr1 = value;
  int *ptr2 = value + 2;
  int *ptr3 = value - 6;

  int ret = 0;

  ret = *ptr1 +  //No problem.
    *ptr1 -
    *ptr2;

  ret = *ptr1 +
    *ptr2 -
    *ptr3; //@violation UNDERRUN.STATIC

}
