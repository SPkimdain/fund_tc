// @checker MISSING_LOGIN_CONTROL


#define TRUE 1

void login1()
{
  // empty condition
  for(;;) { // @violation MISSING_LOGIN_CONTROL
  }
}


void login2()
{
  // constant condition
  for(;1;) { // @violation MISSING_LOGIN_CONTROL
  }
}



void login3()
{
  // constant condition
  for(;TRUE;) { // @violation MISSING_LOGIN_CONTROL
  }
}



void login4()
{
  // constant condition
  while(1) { // @violation MISSING_LOGIN_CONTROL
  }
}




void login5()
{
  // constant condition
  while(TRUE) { // @violation MISSING_LOGIN_CONTROL
  }
}



void login6()
{
  // constant condition
  do {// @violation MISSING_LOGIN_CONTROL
  } while(1); 
}



void login7()
{
  // constant condition
  do {// @violation MISSING_LOGIN_CONTROL
  } while(TRUE); 
}


void login8()
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
    login1();// @violation MISSING_LOGIN_CONTROL
  } while(1); 
}
