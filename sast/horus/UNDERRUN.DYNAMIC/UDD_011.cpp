
/* UDD_011 - Complex call expression */
int* UDD_011_function1(int value, int* ptr) {
  if(value > 10) {
    return ptr;
  }
  else {
    return ptr - 5;
  }
}

void UDD_011_function2() {
  int* value = new int[5];
  if(value == 0) {
    return;
  }

  int ret = 0;

  ret = *(UDD_011_function1(20, value)) +
    *(UDD_011_function1(30, value)); // No problem.

  ret = *(UDD_011_function1(11, value)) + // Ok.
    *(UDD_011_function1(15, value + 1)) + // Ok.
    *(UDD_011_function1(1, value)); // @violation UNDERRUN.DYNAMIC

  delete[] value;
}
