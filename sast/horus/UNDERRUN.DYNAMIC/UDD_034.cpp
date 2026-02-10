

/* UDD_034 - access [], deep callgraph */
void UDD_034_function1(char *p) {
  p[-10] = 'a'; 
}

void UDD_034_function2(char *p) {
  UDD_034_function1(p);
}

void UDD_034_function3(char *p) {
  UDD_034_function2(p);
}

void UDD_034_function4() {
  char* p = new char[5];
  if(p == 0) {
    return;
  }

  UDD_034_function3(p);	//@violation UNDERRUN.DYNAMIC

  delete[] p;
}
