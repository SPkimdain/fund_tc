//@checker IMPROPER_TYPE_ASSIGN

void IMPTA_002_function() {  
  bool b1b = false; //It's ok.
  bool b1a = 1; //@violation IMPROPER_TYPE_ASSIGN  
}

