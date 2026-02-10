//@checker	BAD_EQUALITY_EXPRESSION.BOOLEAN

int main()
{
	int value;
	if(value == 1)	//@violation	BAD_EQUALITY_EXPRESSION.BOOLEAN
	{
		return 1;
	}
	
	return 0;
}