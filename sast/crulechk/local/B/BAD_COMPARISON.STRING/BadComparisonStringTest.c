//@checker BAD_COMPARISON.STRING
extern char * strcpy ( char * destination, const char * source );

void good_func(char* var){
  if(strcpy(var, "love") == 0){
    //.....
  }
}

void bad_func(char* var){
  if(var == "love"){	//@violation BAD_COMPARISON.STRING
    //.....
  }
}