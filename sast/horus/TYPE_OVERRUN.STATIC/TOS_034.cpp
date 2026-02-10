

/* TOS_034 - access [], deep callgraph */
struct TOS_034_Struct {
  int i;
  char c;
  long l;
  char p[5];
};

void TOS_034_function1(char *p) {
  p[10] = 'a'; 
}

void TOS_034_function2(char *p) {
  TOS_034_function1(p);
}

void TOS_034_function3(char *p) {
  TOS_034_function2(p);
}

void TOS_034_function4() {
  TOS_034_Struct sb;
  TOS_034_function3(sb.p);	//@violation TYPE_OVERRUN.STATIC
}
