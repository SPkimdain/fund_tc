#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <stdarg.h>

/* UNINIT */

extern void UN_062_version_etc_va(void *stream, const char *command_name, const char *package,
  const char *version, va_list authors);


void UN_062_version_etc(void *stream, const char *command_name, const char *package,
  const char *version, ...) {
  va_list authors;  
  va_start (authors, version);
  UN_062_version_etc_va(stream, command_name, package, version, authors); //It's ok.
  va_end (authors); 
  
  int a;
  int b;
  b = a; //@violation UNINIT
}
