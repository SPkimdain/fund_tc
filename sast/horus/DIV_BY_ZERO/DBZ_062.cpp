
/* DBZ_-062 - many summary */
int DBZ_062_function(int flag) {
  switch(flag) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    return 1;
  case 5:
  case 7:
  case 8:
  case 9:
  case 10:
  case 11:
  case 12:
  case 13:
  case 14:
    return 2;
  case 15:
    return 0;
  case 16:
  case 17:
    return 3;
  case 18:
  case 19:
    return 4;
  default:
    return 5;
  }
}

int DBZ_062_function2(int flag) {

  int ret = 10000;
  int div = 1;
  if(flag > 12) {
    div = DBZ_062_function(flag);
  }
  
  return ret / div; //@violation DIV_BY_ZERO
}


