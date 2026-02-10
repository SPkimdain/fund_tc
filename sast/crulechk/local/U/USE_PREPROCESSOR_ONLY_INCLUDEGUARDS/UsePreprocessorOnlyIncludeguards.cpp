//@checker USE_PREPROCESSOR_ONLY_INCLUDEGUARDS
#ifndef HDR
#define HDR
#define X(Y) (Y) //@violation USE_PREPROCESSOR_ONLY_INCLUDEGUARDS
#endif

int testmain()
{
	return X(5);
	
}