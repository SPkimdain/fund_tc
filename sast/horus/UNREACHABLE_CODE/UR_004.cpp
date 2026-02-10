//@checker UNREACHABLE_CODE

int UR_004_function(int flag){

  int a = 0;
  int b = 1;
  int ret = 0;

  if(flag > 10) {
    switch(a) { //@violation UNREACHABLE_CODE
    case 0:
      ret = 1;
      break;
    case 1:
      ret = 5;
      break;
    case 2:
      ret = 10;
      break;
    }    
  }

  return ret;
}
