#include <stdlib.h>
/* DF_004 - RETURN_LOCAL struct example */


struct DF_004_struct{
	int val;
	int val2;
	int* ptr2;	
};

int* DF_004_function(int val, int val2, int *p){
	DF_004_struct str;
	str.val = val;
    str.val2 = val2;
	str.ptr2 = (int *)malloc(4);
	if(val > val2){
		free(str.ptr2);
	}
	else{
		return str.ptr2;
	}
	if(val > 10){
		free(str.ptr2); //@violation DOUBLE_FREE
		return 0;
	}
	else{
		return p;
	}
}
