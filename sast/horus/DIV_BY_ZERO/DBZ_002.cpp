

/* DBZ_002 - divide by zero value. */
void DBZ_002_function() {
  int value = 10;
  int p = 100;
  p = p / value; //It's ok.
  value = 0;
  int p2 = 200;
  p2 = p2 / value; //@violation DIV_BY_ZERO
}
