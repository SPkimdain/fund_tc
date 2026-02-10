
/* DBZ_017 - unary operator order */
void DBZ_017_function() {
  int p = 10;
  int p2 = 0;
  int* ptr = 0;
  int ret = 0;
  int* arr[2];

  arr[0] = &p;
  arr[1] = &p2;

  int index = 0;

  ptr = arr[index++]; // index + 1 after assign arr[0].

  ret = 1000 / *ptr; // It's ok.

  index = 0;
  ptr = arr[++index]; // assign arr[1] after index + 1.
  ret = 1000 / *ptr; // @violation DIV_BY_ZERO
}
