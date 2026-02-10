//@checker EMPTY_BRANCH

int alarmCase1(int arg) {
  //Option: check_empty_else_branch
  if(arg == 10) { //It's ok.
    return 0;
  } else {
    return 0;
  }
  
  if(arg == 20) {
    return 10;
  } else { //@violation EMPTY_BRANCH
    //Empty.
  }
  
  if(arg == 30) {
    return 30;
  } else if(arg == 40) { //It's ok.
    return 40;
  } else { //@violation EMPTY_BRANCH
    //Empty.
  }
}

int alarmCase2(int arg) {
  //Option: allow_oneline_if, default is true
  if(arg == 10) { //It's ok.
    return 0;
  } else if(arg == 20) { 
    return 1;
  }
  
  if(arg == 20) { 
    return 0;
  }
  
  if(arg == 30) { //It's ok.
    return 0;
  } else if(arg == 40) { //It's ok.
    return 10;
  } else { //It's ok.
  
    if(arg > 100) //It's ok.
      return 100;
    else if(arg >50) 
      return 200;
      
    return 1;
  }
}

int alarmCase3(int arg, int arg2) {
  int ret = 0;
  //correct case.
  switch(arg) {
  case 0:
    ret++;
    break;
  case 1:
  case 2:
    ret++;
    ret++;
    break;
  default:
    ret--;
    break;
  }
  
  //No case.
  switch(arg2) { //@violation EMPTY_BRANCH
    default:
    ret--;
    break;
  } //@b-violation EMPTY_BRANCH
  
  return ret;
}

int alarmCase4(int arg) {
  int ret = 0;
  //No default
  switch(arg) { //@violation EMPTY_BRANCH
  case 0:
  case 1:
    ret++;
    break;
  case 3:
    ret--;
    break;
  } //@b-violation EMPTY_BRANCH
  
  return ret;
}

int alarmCase5(int arg) {
  int ret = 0;
  //Option: check_empty_case
  //Empty case.
  switch(arg) { //@violation EMPTY_BRANCH
  case 0:
  case 1: //It's ok
    ret++;
    break;
  case 2:
    break;
  case 3:
  case 4:
  case 5:
  case 6:
    break;
  default:
    ret--;
  }
  
  return ret;
}

int alarmCase6(int arg, int arg2, int arg3) {
  //Option: check_empty_default_case
  int ret = 0;
  switch(arg) {
  case 0:
    ret++;
    break;
  default:
    ret--; //It's ok(no break).
  }
  
  switch(arg2) { //@violation EMPTY_BRANCH
  case 0:
    ret++;
    break;
  default: 
    break; 
  }
  
  switch(arg3) { //@violation EMPTY_BRANCH
  case 0:
    ret++;
    break;
  default: 
    ;
  } //@b-violation EMPTY_BRANCH
  
  return ret;
}
