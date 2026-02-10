// @checker MISSING_PASSWORD_RECOVERY_CONTROL


#define TRUE 1

void password_recovery1()
{
  // empty condition
  for(;;) { // @violation MISSING_PASSWORD_RECOVERY_CONTROL
  }
}


void password_recovery2()
{
  // constant condition
  for(;1;) { // @violation MISSING_PASSWORD_RECOVERY_CONTROL
  }
}



void password_recovery3()
{
  // constant condition
  for(;TRUE;) { // @violation MISSING_PASSWORD_RECOVERY_CONTROL
  }
}



void password_recovery4()
{
  // constant condition
  while(1) { // @violation MISSING_PASSWORD_RECOVERY_CONTROL
  }
}




void password_recovery5()
{
  // constant condition
  while(TRUE) { // @violation MISSING_PASSWORD_RECOVERY_CONTROL
  }
}



void password_recovery6()
{
  // constant condition
  do {// @violation MISSING_PASSWORD_RECOVERY_CONTROL
  } while(1); 
}



void password_recovery7()
{
  // constant condition
  do {// @violation MISSING_PASSWORD_RECOVERY_CONTROL
  } while(TRUE); 
}


void password_recovery8()
{
  // empty condition
  for(int a= 0; a= 1;) { // false negative
  }
}



void random_function()
{
  while(TRUE) { // avoid false alarm
  }
}



void bar()
{
  do {
    password_recovery1();// @violation MISSING_PASSWORD_RECOVERY_CONTROL
  } while(1); 
}
