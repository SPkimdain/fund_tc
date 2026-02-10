

/* ND_038 - two dereference3 from opus */
void ND_038_function1(char** pp) {
  **pp = 'a'; 
}

void ND_038_function2() {
  char* p = 0;
  ND_038_function1(&p);	//@violation NULL_DEREF
}

