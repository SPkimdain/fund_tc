
/* DZMC_001 - Very simple example. */
void DZMC_001_function(int i) {
  int a = 10;
  int b,c;
  if(i != 0){
    b = a/i;
  }
  c = a/i; //@violation DIV_BY_ZERO.MISSING_CHECK  
}
