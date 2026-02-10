//@checker UNCONTROLLED_RECURSION

int fac(int n)
{
	return n*fac(n-1); //@violation UNCONTROLLED_RECURSION
}


