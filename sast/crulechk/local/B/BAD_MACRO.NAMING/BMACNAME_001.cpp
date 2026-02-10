//@checker BAD_MACRO.NAMING
#define test 1 //@violation BAD_MACRO.NAMING
#define _MINIMUM_VALUE 2  //@violation BAD_MACRO.NAMING
#define TEST_VAL 3 //It's ok.

void BMACNAME_001_function() {
  //dummy.
  int x = 0;
  
  return;
}

