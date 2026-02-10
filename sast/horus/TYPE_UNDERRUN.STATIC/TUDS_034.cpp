

/* TUDS_034 - access [], deep callgraph */
struct TUDS_034_Struct {
  int i;
  char c;
  long l;
  char p[5];
};

void TUDS_034_function1(char *p) {
  p[-10] = 'a'; 
}

void TUDS_034_function2(char *p) {
  TUDS_034_function1(p);
}

void TUDS_034_function3(char *p) {
  TUDS_034_function2(p);
}

void TUDS_034_function4() {
  TUDS_034_Struct sb;
  TUDS_034_function3(sb.p);	//@violation TYPE_UNDERRUN.STATIC
}
