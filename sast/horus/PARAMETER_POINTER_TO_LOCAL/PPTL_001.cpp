/* PPTL_001 - simple case */

void PPTL_001_function(int **x, int n, int* ptr){
  int y = 7;
  if (n > 10){
    *x = &y; //@violation PARAMETER_POINTER_TO_LOCAL
  } else {
    *x = ptr; //It's ok.
  }
}

