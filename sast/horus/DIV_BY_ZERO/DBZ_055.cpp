
/* DBZ_055 assign operator */
void DBZ_055_function() {
  int* ptr = 0;
  int value = 1;
  value += 10;
  value += 20;
  value += 10;

  int ret = 10000 / (value - 41); //@violation DIV_BY_ZERO
  
}

