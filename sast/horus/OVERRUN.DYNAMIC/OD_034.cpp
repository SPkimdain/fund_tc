

/* OD_034 - access [], deep callgraph */
void OD_034_function1(char *p) {
  p[10] = 'a'; 
}

void OD_034_function2(char *p) {
  OD_034_function1(p);
}

void OD_034_function3(char *p) {
  OD_034_function2(p);
}

void OD_034_function4() {
  char* p = new char[5];
  if(p == 0) {
    return;
  }

  OD_034_function3(p);	//@violation OVERRUN.DYNAMIC

  delete[] p;
}
