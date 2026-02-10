//@checker PLACE_SIGNED_CHAR
extern int printf ( const char * format, ... );

void PSIGNCHAR_001_function(const unsigned char ch) {

  switch(ch){
  case 'a': //@violation PLACE_SIGNED_CHAR
    printf("a!");
    break;
  case 77:
    printf("77!");
    break;
  default:
    printf("default");
    break;
  }
}

