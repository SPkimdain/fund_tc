//@checker USE_CONST_WHENEVER_POSSIBLE

int UCWEP_006_function(int a[5]) { //@violation USE_CONST_WHENEVER_POSSIBLE
  
  return a[0];
}

int UCWEP_006_function2(int a[5]) {  
  a[0] = 10;

  return a[0];
}

const char* UCWEP_006_function4(const char str[5]) {

  return str;
}

const char* UCWEP_006_function5(char str[5]) {

  str[0] = 'x';

  return str;
}
