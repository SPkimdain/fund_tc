#include <stdlib.h>

/* LM_050 - argument field */
struct LM_050_Struct {	
	int* value;
};

void LM_050_function(LM_050_Struct* ptr) {
	if(ptr != NULL){
		ptr->value = (int *) malloc(sizeof(int)); //It's ok.
	}
}

void LM_050_function2() {
  int * ptr = (int*)malloc(4); 
} //@violation LEAK.MEMORY

