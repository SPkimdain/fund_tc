// @checker NO_SIDE_EFFECT_STMT
#include "custom_typedef.h"

void func_no_side_effect_stmt()
{
	uint8_t u8a;
	static volatile uint16_t u16a;
	int32_t a;
	int32_t b;
	int32_t *p;
	volatile int *p1;


	const char *p2 = "asdf";
	p2 += 2;

	*p++;	//@violation NO_SIDE_EFFECT_STMT
	if (b == 1){
	  ++p1;
	}

	
	++p; 
	(*p)++;
	
	(void) *(p1++);	

  ; //@violation NO_SIDE_EFFECT_STMT
	

	1+ u8a++;

	u8a<0;	//@violation NO_SIDE_EFFECT_STMT
	u8a;	//@violation NO_SIDE_EFFECT_STMT

	u8a++;
	

	u16a;
	if(u8a == 0)
	{
		; //@violation NO_SIDE_EFFECT_STMT
	}

}



