// @checker DO_NOT_USE_HEXADECIMAL_ESCAPE

typedef char char_t;

void foo(void)
{
  char octal_escape, n_octal_escape;
  
    char *s1 = "\x41g";     /* Non-compliant */ //@violation DO_NOT_USE_HEXADECIMAL_ESCAPE
   

  /*
  Not pass on MSVC
  n_octal_escape = '\01';    
  n_octal_escape = '\016';   */ 
  octal_escape = '\0';
  //n_octal_point = 0;
}
