// @checker DO_NOT_USE_OCTAL_ESCAPE

typedef char char_t;

void DNUOCTES_001_function(void)
{
  char octal_escape, n_octal_escape;
  char_t * n_octal_point = "x";
  n_octal_escape = '\01';    //@violation DO_NOT_USE_OCTAL_ESCAPE
  n_octal_escape = '\016';   //@violation DO_NOT_USE_OCTAL_ESCAPE
  octal_escape = '\0';
  n_octal_point = 0;
}
