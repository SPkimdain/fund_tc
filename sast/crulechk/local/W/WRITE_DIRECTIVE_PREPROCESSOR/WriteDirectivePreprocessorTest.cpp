//@checker WRITE_DIRECTIVE_PREPROCESSOR

#include <stdio.h>

	#ifdef SOME_FLAG //@violation WRITE_DIRECTIVE_PREPROCESSOR
#	define SOME_OTHER_FLAG //@violation WRITE_DIRECTIVE_PREPROCESSOR
 #else //@violation WRITE_DIRECTIVE_PREPROCESSOR
# define YET_ANOTHER_FLAG //@violation WRITE_DIRECTIVE_PREPROCESSOR
#endif


int main()
{
	return 1;

}

