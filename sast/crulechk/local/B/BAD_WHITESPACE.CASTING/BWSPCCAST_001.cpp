// @checker BAD_WHITESPACE.CASTING

extern void BWSPCCAST_001_test(void*);


void BWSPCCAST_001_function(void* a) {
  float x_scale;
  float x_aix_lin;
  int x_coo_end;
    
  x_scale = (float)x_coo_end / x_aix_lin; //It's ok.
  x_scale += (float) x_coo_end * x_aix_lin; //@violation BAD_WHITESPACE.CASTING

  int b = (*(int*)(a))++; //It's ok.
  
  
  int c = (*(int*) (a))++; //@violation BAD_WHITESPACE.CASTING

  int var = 0;
  BWSPCCAST_001_test((void*) &var); //@violation BAD_WHITESPACE.CASTING
}

