//@checker DIRECTLY_APPEND_POINTER_AND_AMPERSAND

class Test
{
public:
	char* member;
	int *member2; // @violation DIRECTLY_APPEND_POINTER_AND_AMPERSAND
};

void foo( int *x ) // @violation DIRECTLY_APPEND_POINTER_AND_AMPERSAND
{
	return;	
}

void bar( int* y )
{
	return;
}

int main()
{
	char* str;
	char *str2; // @violation DIRECTLY_APPEND_POINTER_AND_AMPERSAND

	int x = 0;
	int &y = x; // @violation DIRECTLY_APPEND_POINTER_AND_AMPERSAND
	int& z = x;
}

