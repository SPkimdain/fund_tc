// @checker DO_NOT_REMOVE_CONST

#define notinname(c) ((unsigned int) (c))


int DNRCONST_001_function()
{
	register const char *cp = "name";
	
	if(notinname (*cp++)) //@violation DO_NOT_REMOVE_CONST
	{
		return 0;
	}
	return 1;
}
 


 