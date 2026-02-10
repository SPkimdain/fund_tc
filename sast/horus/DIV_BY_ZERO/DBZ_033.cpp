
/* DBZ_033 - access [] */
void DBZ_033_function1(int data[]) {
  int ret = 1000 / data[0]; // DIV_BY_ZERO
}

void DBZ_033_function2() {
  int data[5] = { 0, };
  DBZ_033_function1(data);//@violation DIV_BY_ZERO
}
