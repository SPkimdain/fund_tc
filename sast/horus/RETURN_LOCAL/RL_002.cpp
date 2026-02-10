
/* RL_002 - RETURN_LOCAL simple example 2 */


char* RL_002_function() {
  char str[4] = "abc";
  return str; //@violation RETURN_LOCAL
}

