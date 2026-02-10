//@checker BAD_STRING_MANAGEMENT
extern int _mbscpy(char* str1, char* str2);

void BSTRMNG_001_function(char *str1, char *str2){
  _mbscpy(str1,str2);  //@violation BAD_STRING_MANAGEMENT
}

