//@checker NAME_IS_USED_IN_STANDARD_LIBRARY


int strcmp( int x ) //@violation NAME_IS_USED_IN_STANDARD_LIBRARY
{
	return x + 10;
}

float ungetc( float y ) //@violation NAME_IS_USED_IN_STANDARD_LIBRARY
{

	return y * 2;
}

void fabs() //@violation NAME_IS_USED_IN_STANDARD_LIBRARY
{
	return;
}

int main()
{
	return 1;
}

