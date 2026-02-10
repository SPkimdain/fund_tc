//@checker DO_NOT_CONVERT_FLOATING_TO_INTEGRAL


enum EastWest
{
	East = 1,
	West = -11
};

void DNCFTI_18959 ()
{
	float dd =100.0f;
	
	enum EastWest ew = East;
	
	ew = ( dd > 0.0 ) ? East : West;

}
