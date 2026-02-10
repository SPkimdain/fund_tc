// @checker DO_NOT_USE_UNDEF
#include <stdio.h>

#define TEST
#undef TEST //@violation DO_NOT_USE_UNDEF

void main()
{

}
