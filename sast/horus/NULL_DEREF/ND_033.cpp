
/* ND_033 - access [] from opus */
void ND_033_function1(char* p) {
  p[0] = 'a'; 
}

void ND_033_function2() {
  char* p = 0;
  ND_033_function1(p);	//@violation NULL_DEREF
}
