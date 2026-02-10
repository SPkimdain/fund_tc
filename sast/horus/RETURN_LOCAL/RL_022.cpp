#include <time.h>
#include <stdlib.h>
#include <malloc.h>

/* RL_022 - static string return. */
char* RL_022_gval;

char* RL_022_function() {
  //source
  char* const_subject = (char*)malloc(100);
  char raw_subject[] = "stack string";
  char* subject = raw_subject;
  //complexity

  srand(time(NULL));
  if(rand() % 2) {
    RL_022_gval = subject;
    free(const_subject);
  }
  else {
    RL_022_gval = const_subject;
  }
  

  return RL_022_gval; //@violation RETURN_LOCAL
}
