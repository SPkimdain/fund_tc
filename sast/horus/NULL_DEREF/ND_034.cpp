

/* ND_034 - access [], deep callgraph, from opus */
void ND_034_function1(char *p) {
  p[0] = 'a'; 
}

void ND_034_function2(char *p) {
  ND_034_function1(p);
}

void ND_034_function3(char *p) {
  ND_034_function2(p);
}

void ND_034_function4() {
  char *p = 0;
  ND_034_function3(p);	//@violation NULL_DEREF
}
