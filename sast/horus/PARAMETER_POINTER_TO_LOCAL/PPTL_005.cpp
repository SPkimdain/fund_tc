

/* PPTL_005 - field pointer out */
struct PPTL_005_Struct {
  char* ptr;
};

extern void PPTL_005_function(PPTL_005_Struct* acc);

char* PPTL_005_function2(PPTL_005_Struct* acc) {
  return acc->ptr;
}

void PPTL_005_function3(PPTL_005_Struct*& out) {
  char* z = 0;
  PPTL_005_Struct obj;

  PPTL_005_function(&obj);

  z = PPTL_005_function2(&obj);

  out->ptr = z; //It's ok.
}

void PPTL_005_function(int **x, int n, int* ptr){
  int y = 7;
  if(n > 10){
    *x = &y; //@violation PARAMETER_POINTER_TO_LOCAL
  }
}
