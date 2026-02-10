
/* ND_056 - global variable */
int ND_056_Var = 10;
int* ND_056_pVar = &ND_056_Var;

void ND_056_function1() {
  ND_056_pVar = 0;
}

void ND_056_function2() {
  ND_056_function1();

  *ND_056_pVar = 1000; //@violation NULL_DEREF
}
