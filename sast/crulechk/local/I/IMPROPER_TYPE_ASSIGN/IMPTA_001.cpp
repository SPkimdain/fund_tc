//@checker IMPROPER_TYPE_ASSIGN

void IMPTA_001_function() {  
  unsigned int u32a = 1.0f; //@violation IMPROPER_TYPE_ASSIGN
  unsigned int u32b = 3000; //It's ok.

}

