//@checker WRONG_NUMBER_OF_PARAMETERS_IN_MACRO
#define MY_MACRO(X, Y) ((X) * (Y)) 
#define MY_MACRO2(X, Y) ((X) * (Y))

void WRNOPARAMIM_001_function(){
	
  int k = MY_MACRO(1); /* bad */  //@violation WRONG_NUMBER_OF_PARAMETERS_IN_MACRO
	int y = MY_MACRO2(1,2);
	
}
