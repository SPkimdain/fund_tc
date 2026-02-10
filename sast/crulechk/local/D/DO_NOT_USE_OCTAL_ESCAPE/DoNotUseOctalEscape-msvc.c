// @checker DO_NOT_USE_OCTAL_ESCAPE

typedef char char_t;

void DNUOCTES_002_function(void)
{
  char octal_escape, n_octal_escape;
  
    char *s1 = "\041g";     //@violation DO_NOT_USE_OCTAL_ESCAPE
   

  /*
  Not pass on MSVC
  n_octal_escape = '\01';    
  n_octal_escape = '\016';   */ 
  octal_escape = '\0';
  //n_octal_point = 0;
}
