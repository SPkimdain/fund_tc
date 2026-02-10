
void NDMC_001_function(char * x) {
  char y1, y2;
  if(x != 0){
    y1 = *x;
  }

  y2 = *x;  //@violation NULL_DEREF.MISSING_CHECK
}
