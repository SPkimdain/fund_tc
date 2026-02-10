//@checker BAD_MACRO.TRAILING_SEMICOLON
#define ADD(X, Y) (X) = (X) + (Y);  //@violation BAD_MACRO.TRAILING_SEMICOLON

void BMACTSEMC_001_function(int a, int b) { 
  ADD(a, b);
}
