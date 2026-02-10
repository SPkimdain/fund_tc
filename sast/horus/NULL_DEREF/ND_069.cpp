#include <stdlib.h>
/* ND_069 - null dereference repetition. */



void ND_069_function(int *p2) {
	
	int* p1 = 0;

	if (*p1 == 3){ //@violation NULL_DEREF
		if (*p1==1){ // no alarm
			int tmp = *p2;
		}
		else{			
			*p1 = 1; // no alarm
		}
	}
	
}


