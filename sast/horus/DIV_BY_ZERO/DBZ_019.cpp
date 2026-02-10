
/* DBZ_019 - short circuit2 */
void DBZ_019_function() {
  int p = 20;
  int x = 10;
  int compareValue = 20;
  int ret = 0;

  //x != 10 so &&'s right hand side doesn't evaluation.
  ret = 100 / p; //p is not 0

  if(compareValue = 100 / (p - 20)) { // @violation DIV_BY_ZERO
    x++;
  }
}
