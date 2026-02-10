// @checker DO_NOT_USE_HEXADECIMAL_ESCAPE

typedef char char_t;

void foo(void)
{
  char octal_escape, n_octal_escape;
  char_t * n_octal_point = "\x41g";	//@violation DO_NOT_USE_HEXADECIMAL_ESCAPE
  char_t * n_octal_point3 = "abc\x41g";	//@violation DO_NOT_USE_HEXADECIMAL_ESCAPE
  char_t * n_octal_point2 = "\x41" "g";	//@violation DO_NOT_USE_HEXADECIMAL_ESCAPE
  
  n_octal_escape = '\x41\t';   //@violation DO_NOT_USE_HEXADECIMAL_ESCAPE
  n_octal_escape = '\x41';   //@violation DO_NOT_USE_HEXADECIMAL_ESCAPE
  n_octal_escape = '\01';   
  n_octal_escape = '\016';  
  octal_escape = '\0'; 
  n_octal_point = 0;
  
  
  
}
