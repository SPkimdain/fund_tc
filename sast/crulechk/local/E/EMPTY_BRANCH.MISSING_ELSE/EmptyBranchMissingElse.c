//@checker EMPTY_BRANCH.MISSING_ELSE

int alarmCase1(int arg) {
  
  if(arg == 10) { 
    return 0;
  } else {
    return 0;
  }
  
  if(arg == 20) {
    return 10;
  } else { 
  
  }
  
  if(arg == 30) {
    return 30;
  } else if(arg == 40) { 
    return 40;
  } else { 
    
  }
}

int alarmCase2(int arg) {
  
  if(arg == 10) { 
    return 0;
  } else if(arg == 20) { //@violation EMPTY_BRANCH.MISSING_ELSE
    return 1;
  }
  
  if(arg == 20) { //@violation EMPTY_BRANCH.MISSING_ELSE
    return 0;
  }
  
  if(arg == 30) { 
    return 0;
  } else if(arg == 40) { 
    return 10;
  } else { 
  
    if(arg > 100) 
      return 100;
    else if(arg >50) 	//@violation EMPTY_BRANCH.MISSING_ELSE
      return 200;
      
    return 1;
  }
}