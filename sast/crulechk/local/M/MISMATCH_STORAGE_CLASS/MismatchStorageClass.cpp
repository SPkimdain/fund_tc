#include "Test.h"
//@checker MISMATCH_STORAGE_CLASS

extern int number; //@b-violation MISMATCH_STORAGE_CLASS

extern int number2;

extern int number3; //@b-violation MISMATCH_STORAGE_CLASS

extern void func(); //@b-violation MISMATCH_STORAGE_CLASS

extern void func2();

//static void func3();

static int number; //@violation MISMATCH_STORAGE_CLASS

int number2; // OK.

static int number3 = 4; //@violation MISMATCH_STORAGE_CLASS

static void func() { //@violation MISMATCH_STORAGE_CLASS
  int x = 0;
}

void func2() { // OK.
  int x = 10;
}

extern void func3() { //@violation MISMATCH_STORAGE_CLASS
  int x = 20;
}

int MMSTRGCLS_001_function() {
  int x = number;
  func3();
  return 0;
}

