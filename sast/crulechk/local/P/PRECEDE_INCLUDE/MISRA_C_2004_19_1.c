// @checker PRECEDE_INCLUDE
#pragma once

#ifndef /* TEST */ TEST
#define TEST 10
#define MACRO(t) t + 5
#undef TEST

/*
#define TEST3 15
*/

#include <stdio.h>
#include <stdlib.h>


enum
{
	apple
};

void foo()
{
	printf("#include <stdio.h>");
}

/* SameLine1 */ int /* SameLine2 */ x; /* SameLine3 #undef */
int y;
int z;

// LINE TEST4 \
effef "No String" \
#define TEST5 10 wefef \
efefe \

#include <stdio.h> // @violation PRECEDE_INCLUDE 

    #include /*<???> */ <string.h> // @violation PRECEDE_INCLUDE 
//#include <stdio.h>
/* */ /* #include <stdio.h> */
void main()
{
	int x = 0;
	//x = MACRO(4);
	printf("%d /* String Test */\
	//Test 2 \
	/*\
	TEST3\
	*/\
	\n",x);
	
	char xy = 'x';
}

#endif

