char const *p ;

void test() {
  char const str[] = "string";
  p = str; // @violation
}
// Address of stack memory associated with local variable 'str' is still referred to by the global variable 'p' upon returning to the caller.
// This will be a dangling reference

void* test2() {
   return __builtin_alloca(12); // @violation
    // Address of stack memory allocated by call to alloca() on line 8 returned to caller
}

void* test2_1() {
	void * temp  = __builtin_alloca(21);
   return temp; // @violation
    // Address of stack memory allocated by call to alloca() on line 8 returned to caller
}


void test3() {
  static int *x;
  int y;
  x = &y; // @will-violation
}
// Address of stack memory associated with local variable 'y' is still referred to by the global variable 'x' upon returning to the caller.
// This will be a dangling reference