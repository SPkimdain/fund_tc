//@checker BAD_INCLUDE.INVALID_PATH

#ifdef _WIN32

#include "includes\test.h" //@violation BAD_INCLUDE.INVALID_PATH

#else

#include "includes/test.h" //@violation BAD_INCLUDE.INVALID_PATH

#endif
