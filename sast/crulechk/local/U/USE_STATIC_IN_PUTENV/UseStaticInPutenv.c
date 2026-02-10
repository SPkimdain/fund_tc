// @checker USE_STATIC_IN_PUTENV
extern int snprintf ( char * s, long n, const char * format, ... );
extern int putenv(const char *str);

int func(const char *var) {
  char env[1024];
  static char env1[512];
  char* env2;
  int retval = snprintf(env, sizeof(env),"TEST=%s", var);
  if (retval < 0 || (long)retval >= sizeof(env)) {
    /* Handle error */
  }

  putenv(env1);
  putenv(env2);
 
  return putenv(env);	//@violation	USE_STATIC_IN_PUTENV
}
