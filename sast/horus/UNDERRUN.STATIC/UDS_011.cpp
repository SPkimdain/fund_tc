
/* UDS_011 - Complex call expression */
int* UDS_011_function1(int value, int* ptr) {
  if(value > 10) {
    return ptr;
  }
  else {
    return ptr - 5;
  }
}

void UDS_011_function2() {
  int value[5] = { 1, };

  int ret = 0;

  ret = *(UDS_011_function1(20, value)) +
    *(UDS_011_function1(30, value)); // No problem.

  ret = *(UDS_011_function1(11, value)) + // Ok.
    *(UDS_011_function1(15, value + 1)) + // Ok.
    *(UDS_011_function1(1, value)); // @violation UNDERRUN.STATIC
}
