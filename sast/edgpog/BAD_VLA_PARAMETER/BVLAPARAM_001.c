//@checker BAD_VLA_PARAMETER

void BVLAPARAM_001_function1(short n, short(*a)[n]) { //@violation BAD_VLA_PARAMETER
  short(*p)[20];
  p = a;  
}


void BVLAPARAM_001_safe(short n, short* a) { 
  short* p;
  p = a;
}

