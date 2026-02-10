#include <stdlib.h>
/* ND_068 - null dereference repetition. */

struct ND_068_struct{
	int val;
	int val2;
	int* ptr2;	
};

void ND_068_function(ND_068_struct *p, int *p2) {
	ND_068_struct* sptr = NULL;
	

	
	sptr->val2 = 1; //@violation NULL_DEREF
	sptr->val = 3; // no alarm
		
}


