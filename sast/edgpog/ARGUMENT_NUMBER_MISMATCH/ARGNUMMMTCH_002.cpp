//@checker ARGUMENT_NUMBER_MISMATCH

int ARGNUMMMTCH_002_function(int val, int val2, int val3) {
  return val * val2 / val3;
}

void ARGUMENT_NUMBER_MISMATCH_caller() {
  ARGNUMMMTCH_002_function(20); //@violation ARGUMENT_NUMBER_MISMATCH
  
}
