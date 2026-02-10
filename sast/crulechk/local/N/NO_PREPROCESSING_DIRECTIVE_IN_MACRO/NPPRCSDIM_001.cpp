//@checker NO_PREPROCESSING_DIRECTIVE_IN_MACRO
#define MULTI(X,Y) ((X) * (Y))


void NPPRCSDIM_001_function(int p1, int p2) {
  MULTI(10, //@violation NO_PREPROCESSING_DIRECTIVE_IN_MACRO
#ifdef X64
 p1);
#else
 p2);
#endif
}
