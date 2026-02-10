
/* ND_063 - assert2 */
#include <assert.h>

int ND_063_function(char* p, char* p2) {

	assert(p && *p && p2 && *p2);
  
  int* x = 0;
  *x = 100; //@violation NULL_DEREF
  
	return 0;  
}
