//@checker DO_NOT_ASSERT_AFTER_ATEXIT
extern int atexit(void (*func)(void));
extern void assert(int exp);

void DNAAA_001_cleanup(void) {
  /* Delete temporary files, restore consistent state, etc. */
}

int DNAAA_001_function(void) {
  if(atexit(DNAAA_001_cleanup) != 0) {
    /* Handle error */
  }
  
  /* ... */
  assert(0); //@violation DO_NOT_ASSERT_AFTER_ATEXIT
  /* ... */

  return 0;
}

