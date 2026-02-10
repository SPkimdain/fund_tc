//@checker USE_FUNCTION_IN_IF_CONDITION
extern int strcmp ( const char * str1, const char * str2 );

int doSomething(int arg) {
  return arg + 10;
}

char* getStr() {
  return "12345";
}

int function(int arg, char* str) {
  int count = 0;
  if(arg > 10) { //It's ok.
    count++;
  }

  if(strcmp("1234", str) == 0) { //It's ok. excepted function.
    count++;
  }

  if(doSomething(5) == 10) { //@violation USE_FUNCTION_IN_IF_CONDITION
    count++;
  }

  if(strcmp(getStr(), str) == 0) { //@violation USE_FUNCTION_IN_IF_CONDITION
    count++;
  }  
}
