//@checker SIDE_EFFECT.INITIALIZER_LISTS
typedef unsigned short uint16_t;

uint16_t x = 0u;
extern void p(uint16_t a2[2]);

void h( void)
{
	p((uint16_t[2]){x++, x++});	// @violation SIDE_EFFECT.INITIALIZER_LISTS
}

volatile uint16_t v1;

void g( void )
{
	uint16_t a[2] = {v1, 0};// @violation SIDE_EFFECT.INITIALIZER_LISTS
}

void f(uint16_t x, uint16_t y)
{
	uint16_t a1[2] = {x + y, x - y};	// okay
}
