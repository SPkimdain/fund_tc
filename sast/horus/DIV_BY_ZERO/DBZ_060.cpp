
/* DBZ_060 - divide by zero repetition. */
void DBZ_060_function() {  
  int a = 0;
  int b = 3;
  int c = b / a;  //@violation DIV_BY_ZERO
  int d = b / a;  // no alarm
}
