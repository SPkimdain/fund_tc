/* MR_002 - simple case2 */

int MR_002_function(int flag) {
  int mrValue = 0;
  
  switch(flag) {
  case 0:
    mrValue++;
    return mrValue + flag;

  case 1:
    return 10;

  case 2:
    return 20;

  case 10:
    return 11;

  default:
    break;
  }

} //@violation MISSING_RETURN


