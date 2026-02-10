//@checker INCLUDE_EXPLICIT_CASES_FOR_ALL_ALTERNATIVES

enum EnumList
{
	apple,
	melon,
	grape,
	orange
};

enum EnumList2
{
	FIRST,
	SECOND,
	TWO = SECOND,
	THIRD
};

int main()
{
	int x = 10;
	
	switch( x )
	{
	case 1:
	case 2:
	case 3:
		break;
	default:
		break;
	}
	
	switch( x ) 
	{
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	}

	switch( x ) //@violation INCLUDE_EXPLICIT_CASES_FOR_ALL_ALTERNATIVES
	{ 
	case 1:
		break;
	case 3:
		break;
	case 4:
		break;
	}

	EnumList el = apple;

	switch( el )
	{
	case apple:
	case melon:
	case grape:
		break;
	case orange:
		break;
	}

	switch( el ) //@violation INCLUDE_EXPLICIT_CASES_FOR_ALL_ALTERNATIVES
	{ 
	case apple:
	case melon:
		break;
	case orange:
		break;
	}

	EnumList2 el2 = FIRST;

	switch( el2 )
	{
	case FIRST:
		break;
	case SECOND:
		break;
	case THIRD:
		break;
	}

	return 1;
}
