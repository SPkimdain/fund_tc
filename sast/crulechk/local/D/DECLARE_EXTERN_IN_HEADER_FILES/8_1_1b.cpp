//@checker DECLARE_EXTERN_IN_HEADER_FILES

#include "8_1_1b.h"


extern int a2;  //@violation DECLARE_EXTERN_IN_HEADER_FILES

int a = 10;

float f4 = 3.0E8; //as misra2008-spec //@violation DECLARE_EXTERN_IN_HEADER_FILES

namespace 
{
	extern int a3;
	int x2 =  0;
}
