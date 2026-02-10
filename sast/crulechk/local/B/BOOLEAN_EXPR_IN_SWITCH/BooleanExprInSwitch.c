// @checker BOOLEAN_EXPR_IN_SWITCH

typedef int boolean_t;

void BOOLEXPRIS_001_function(int foo, int bar)
{
	switch((bar != 0) && foo == 1) {	// @violation	BOOLEAN_EXPR_IN_SWITCH
		case 0:
			bar = 2;
			break;
		default:	
			bar = 1;
			break;
	}
	switch(bar)
	{
	case 0:
		foo = 1;
		break;
	default:
		foo = 2;
		break;
	}
}
