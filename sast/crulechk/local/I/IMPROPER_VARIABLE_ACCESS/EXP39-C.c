//@checker IMPROPER_VARIABLE_ACCESS

union a_union {
  int i;
  double d;
};
 
int f() {
  double d = 3.0;
  return ((union a_union *) &d)->i;  //@violation IMPROPER_VARIABLE_ACCESS
}
