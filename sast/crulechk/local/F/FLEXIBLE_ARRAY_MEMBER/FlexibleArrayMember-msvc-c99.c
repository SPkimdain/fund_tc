// @checker FLEXIBLE_ARRAY_MEMBER

struct flexArrayStruct {
  int num;
  int data[];	//@violation FLEXIBLE_ARRAY_MEMBER
};

struct flexArrayStruct1 {
  int num1;
  int data1[1];
};


void FLEXAM_001_function1(){
	struct flexArrayStruct flexStruct;
	unsigned array_size;
	unsigned i;
	
	struct flexArrayStruct *flexStructA;
	struct flexArrayStruct *flexStructB;

	*flexStructB = *flexStructA;	
}