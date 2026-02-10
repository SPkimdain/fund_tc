
/* ND_039 - two dereference4 from opus */
void ND_039_function1(char** pp) {
  **pp = 'a';
}

void ND_039_function2(char** pp) {
  ND_039_function1(pp);
}

void ND_039_function3(char* p) {
  ND_039_function2(&p);
}

void ND_039_function4() {
  char *p = 0;
  ND_039_function3(p);	 //@violation NULL_DEREF
}
