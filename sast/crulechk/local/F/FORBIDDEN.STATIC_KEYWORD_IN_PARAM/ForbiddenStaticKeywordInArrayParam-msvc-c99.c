//@checker FORBIDDEN.STATIC_KEYWORD_IN_PARAM

typedef short int16_t;
typedef unsigned uint16_t;

uint16_t total(uint16_t n, uint16_t a[static 20]) //@violation FORBIDDEN.STATIC_KEYWORD_IN_PARAM
{
	uint16_t i;
	uint16_t sum = 0U;
	
	/* Undefined behaviour if a has fewer than 20 elements */
	for (i = 0U; i < n; ++i)
	{
		sum = sum + a[i];
	}
	
	return sum;
}


extern uint16_t v1[10];
extern uint16_t v2[20];

void g(void)
{
	uint16_t x;
	x = total(10U, v1); // violation
	x = total(20U, v2); // defined, but not-compliant
}