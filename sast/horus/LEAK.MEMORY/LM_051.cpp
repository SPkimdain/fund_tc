#include <stdlib.h>

/* LM_051 - false positive. */

void LM_051_function() {
	char* p;
	for(;;){
		if (p){
			break;
		}
		p = (char *)malloc(10);
	}
	free(p);
}

void LM_051_function2() {
  int * ptr = (int*)malloc(4);
} //@violation LEAK.MEMORY



