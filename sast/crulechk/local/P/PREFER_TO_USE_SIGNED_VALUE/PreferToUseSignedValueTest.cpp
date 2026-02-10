//@checker PREFER_TO_USE_SIGNED_VALUE

typedef unsigned int TypeTest;

class Test
{
public:
	unsigned int member; // @violation PREFER_TO_USE_SIGNED_VALUE
	signed short member2;
	unsigned char member3; // @violation PREFER_TO_USE_SIGNED_VALUE
	unsigned long long member5; // @violation PREFER_TO_USE_SIGNED_VALUE
};

void foo( unsigned int param ) // @violation PREFER_TO_USE_SIGNED_VALUE
{
	return;
}

//Ignore pointer type followed unsigned type.
void bar( unsigned int* param2 ) 
{
	return;
}

int main()
{
	unsigned int val; // @violation PREFER_TO_USE_SIGNED_VALUE
	signed short val2;
	unsigned char val3; // @violation PREFER_TO_USE_SIGNED_VALUE
	unsigned long long val5; // @violation PREFER_TO_USE_SIGNED_VALUE
	TypeTest val6; // @violation PREFER_TO_USE_SIGNED_VALUE
}
