//@checker REDUNDANT_NAME
static int static_a, static_b;
void RDDNAME_001_function() {
  int static_a,static_b;  //@violation REDUNDANT_NAME
}

