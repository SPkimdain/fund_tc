// @checker DO_NOT_CAST_AWAY_CONST

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void noncompliant(char const *str, int slen) {
  char *p = const_cast<char*>(str);   // @violation DO_NOT_CAST_AWAY_CONST
    int i;
    for (i = 0; i < slen && str[i]; i++) {
	if (str[i] != ' ') *p++ = str[i];
    }
}



void compliant(char *str, int slen) {
  char *p = str;
  int i;
  for (i = 0; i < slen && str[i]; i++) {
    if (str[i] != ' ') *p++ = str[i];
  }
}

void DNCACONST_001_function() {
  int const vals[] = {3, 4, 5};
  memset((int*) vals, 0, sizeof(vals));   // @violation DO_NOT_CAST_AWAY_CONST
}
