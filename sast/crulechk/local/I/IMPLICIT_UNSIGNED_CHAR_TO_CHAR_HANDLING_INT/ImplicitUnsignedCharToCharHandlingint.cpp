//@checker IMPLICIT_UNSIGNED_CHAR_TO_CHAR_HANDLING_INT
typedef long size_t;
extern size_t strlen ( const char * str );
extern int isspace ( int c );

size_t count_preceding_whitespace(const char *s) {
  const char *t = s;
  size_t length = strlen(s) + 1;
  while (isspace(*t) && (t - s < length)) { //@violation IMPLICIT_UNSIGNED_CHAR_TO_CHAR_HANDLING_INT
    ++t;
  }
  return t - s;
} 
