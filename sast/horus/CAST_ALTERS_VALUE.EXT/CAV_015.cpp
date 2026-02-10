/* function argument, smaller type */

void CAV_015_function1(char ch) {
  ch++;
}

void CAV_015_function2() {
  int size = 10000;
  CAV_015_function1(size); //@violation CAST_ALTERS_VALUE.EXT
}

