//@checker TYPE_MISMATCH_IN_TERNARY

int func( int x )
{
	return x * 2;
}

float func2( int y )
{
	if( y == 10 )
	{
		return 10.5F;
	}
	else
	{
		return 5.51241F;
	}
}

int main()
{
	int x = 10;
	float y = 5;
	int ret = 0;

	bool checkingFlag = false;

	ret = ( checkingFlag ? x : y ); //@violation TYPE_MISMATCH_IN_TERNARY

	ret = ( checkingFlag ? func( 5 ) : func2( 1 ) ); //@violation TYPE_MISMATCH_IN_TERNARY

	ret = ( checkingFlag ? func( 5 ) : 1000 );

	//float을 리턴하나 해당 체커로 잡지는 않으며, float->integer로 암시적 변환이 일어나는 만큼
	//DO_NOT_CONVERT_FLOATING_TO_INTEGRAL로 잡아야 함.
	ret = ( checkingFlag ? func2( 1 ) : 0.5F );

	return 1;
}

