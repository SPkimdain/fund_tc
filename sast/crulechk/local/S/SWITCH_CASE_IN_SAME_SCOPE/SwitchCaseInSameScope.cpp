//@checker SWITCH_CASE_IN_SAME_SCOPE

void SCISS_temp()
{
	int x= 5;
	switch ( x )
	{
		case 0:
		case 1:
			if( x  > 4) 
			{
				case 2: //@violation SWITCH_CASE_IN_SAME_SCOPE
					return;
			}
			break;
		default:
			break;
	}
}