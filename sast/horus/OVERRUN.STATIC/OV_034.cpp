

/* OV_034 - access [], deep callgraph */
void OV_034_function1(char *p) {
  p[10] = 'a'; 
}

void OV_034_function2(char *p) {
  OV_034_function1(p);
}

void OV_034_function3(char *p) {
  OV_034_function2(p);
}

void OV_034_function4() {
  char p[5] = { 0, };
  OV_034_function3(p);	//@violation OVERRUN.STATIC
}
