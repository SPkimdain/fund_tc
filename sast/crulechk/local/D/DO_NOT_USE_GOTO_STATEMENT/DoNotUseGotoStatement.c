
//@checker DO_NOT_USE_GOTO_STATEMENT

int gotoStatementTest(int x)
{//@violation DO_NOT_USE_GOTO_STATEMENT
	if(x == 10)
	{
		goto position; 
	}
	else
	{
		return 5;
	}

position:
	return 10;
}


