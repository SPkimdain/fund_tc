// @checker BAD_ASSERT_USAGE
#define NULL 0
extern void* malloc (int size);
extern int strlen ( const char * str );
extern void * memcpy ( void * destination, const void * source, int num );
extern void assert (int expression);
 
char* BASTUSG_001_function(const char *c_str) {
  int len = 100;
  int *dup;
  int *bar = (int *)malloc(len);	
  assert(bar != NULL); //@violation BAD_ASSERT_USAGE
 
  len = strlen(c_str);
  dup = (int *)malloc(len + 1);
  assert(NULL != dup);	//@violation BAD_ASSERT_USAGE
 
  memcpy(dup, c_str, len + 1);
  assert(len != 0);
  return 0;
}
