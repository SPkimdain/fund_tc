// @checker BEWARE_USE_FLEXIBLE_ARRAY_MEMBER

struct flexArrayStruct {
  int num;
  int data[];	//@b-violation BEWARE_USE_FLEXIBLE_ARRAY_MEMBER
};

void print_array(struct flexArrayStruct structP) {	//@violation	BEWARE_USE_FLEXIBLE_ARRAY_MEMBER

}


void BWUFAM_001_function2(){
	struct flexArrayStruct flexStruct;	//@violation	BEWARE_USE_FLEXIBLE_ARRAY_MEMBER
	unsigned array_size;
	unsigned i;
	
	struct flexArrayStruct *flexStructA;
	struct flexArrayStruct *flexStructB;

	*flexStructB = *flexStructA;		//@violation	BEWARE_USE_FLEXIBLE_ARRAY_MEMBER
}
