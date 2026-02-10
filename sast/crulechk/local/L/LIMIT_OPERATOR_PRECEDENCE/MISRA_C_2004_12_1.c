// @checker LIMIT_OPERATOR_PRECEDENCE
#define DCM_VIN_SUPPORT 10
#define DCM_CALID_SUPPORT 20

typedef short uint16;

int main()
{
	int a, b, c, d;
	int i = 0;
	
	a = b = c = d = 0;
	
	d = a + b + c - d;
	
	d = a * 2 + b + c; // @violation LIMIT_OPERATOR_PRECEDENCE
	d = ( a * 2 ) + b + c;
	
	d = a >> 2 + b; // @violation LIMIT_OPERATOR_PRECEDENCE

	d = a & b == 1 + 3; // @violation LIMIT_OPERATOR_PRECEDENCE
	
	d = a + b - c * d / 1 % 1 << d >> 1 == a != b & c ^ d | a; // @violation LIMIT_OPERATOR_PRECEDENCE
	
	if( ( a + b ) == 1 )
	{
	}
	if( a & b == 1 ) // @violation LIMIT_OPERATOR_PRECEDENCE
	{
	}
	
	for( i = 0; i & b != 1; i++ ) // @violation LIMIT_OPERATOR_PRECEDENCE
	{
	}

	while( a | b & 0 - 2 ) // @violation LIMIT_OPERATOR_PRECEDENCE
	{
	
	}
	
	return a ^ b != 10; // @violation LIMIT_OPERATOR_PRECEDENCE

}

void  autoever02_05_bad ( void )   {
    const uint16  DcmDataMode_ECUIDSupport = {
        DCM_VIN_SUPPORT << 14 | DCM_CALID_SUPPORT << 12 | 1 << 10 //@violation LIMIT_OPERATOR_PRECEDENCE
    };
}
