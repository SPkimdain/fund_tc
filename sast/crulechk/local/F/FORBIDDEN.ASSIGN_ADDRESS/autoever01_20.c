//@checker FORBIDDEN.ASSIGN_ADDRESS
/*
 * HMG Secure Coding Guide Exemplar Suite
 *
 * Published by Fasoo.com PA Business Division
 *
 * Copyright Fasoo.com
 *
 */

/*
 * Test case of rule 1-20
 * 정수, 포인터간 서로간의 변환을 자제하라( 포인터에 고정 주소 할당을 자제하라 )
 */
#include "autoever01_20.h"
void autoever_01_20_good1(void){
	struct  ptrflag {
		char  *pointer;
		unsigned int flag : 9;
	} ptrflag;

	char  *ptr = 0;
	unsigned  int  flag = 0;

	/* … */

	ptrflag.pointer = ptr;
	ptrflag.flag = flag;


}

int8  autoever_01_20_bad_2 ( void )   {

	int  (*pt2Function) (float, char, char) = 0x08040000;	//@violation FORBIDDEN.ASSIGN_ADDRESS
	int  (*pt3Function) (float, char, char) = 0;
	int result2 = (*pt2Function) (12, 'a', 'b');
	pt3Function = 0x2222222;	//@violation	 FORBIDDEN.ASSIGN_ADDRESS
	/* Here attacker can inject code to excute */
	result2 = (*pt3Function) (12, 'a', 'b');
	return 0;
}
