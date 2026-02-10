//@checker DO_NOT_CAST_FROM_POINTER_TO_INTEGRAL 


using namespace std;

signed int * foo( unsigned int *x );

signed int * foo( unsigned int *x )
{
	return ( signed int * )x;
}

struct str {
long f;
};

int main()
{
	long a = 0;
	double d = 1.5;
	struct str strc = { 24 };
	struct str *s = &strc;
	
  
  
 
	a = (long) (s->f * d);
	
	signed int *ps32a;
	unsigned int *pu32a;
	signed int s32a;
	unsigned int u32a;
	signed int x = 10;
	unsigned int y = 10;
	signed int **pps32a;

	ps32a = &x;
	pu32a = &y;
	pps32a = &ps32a;
	
	u32a = (unsigned int) pu32a; // @violation DO_NOT_CAST_FROM_POINTER_TO_INTEGRAL

	s32a = (signed int) *ps32a + (signed int) *pps32a; // @violation DO_NOT_CAST_FROM_POINTER_TO_INTEGRAL
	s32a = (signed int) *( ps32a + 0 );
	s32a = (signed int) *( 0 + pps32a ); // @violation DO_NOT_CAST_FROM_POINTER_TO_INTEGRAL
	u32a = (unsigned int) foo( pu32a ); // @violation DO_NOT_CAST_FROM_POINTER_TO_INTEGRAL
	u32a = (unsigned int) *( foo( pu32a ) ) ;
	
	return 1;
}
