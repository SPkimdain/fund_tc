//@checker ARGUMENT_NUMBER_MISMATCH

int ARGNUMMMTCH_001_function(int val) {
  return val + 10;
}

void ARGUMENT_NUMBER_MISMATCH_caller() {
  ARGNUMMMTCH_001_function(10, 5); //@violation ARGUMENT_NUMBER_MISMATCH
  
}
