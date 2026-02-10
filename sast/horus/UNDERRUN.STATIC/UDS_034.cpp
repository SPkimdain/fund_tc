

/* UDS_034 - access [], deep callgraph */
void UDS_034_function1(char *p) {
  p[-1] = 'a'; 
}

void UDS_034_function2(char *p) {
  UDS_034_function1(p);
}

void UDS_034_function3(char *p) {
  UDS_034_function2(p);
}

void UDS_034_function4() {
  char p[5] = { 0, };
  UDS_034_function3(p);	//@violation UNDERRUN.STATIC
}
