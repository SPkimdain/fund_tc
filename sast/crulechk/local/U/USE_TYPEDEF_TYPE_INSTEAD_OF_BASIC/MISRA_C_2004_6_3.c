// @checker USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC

typedef	char        char_t;
typedef   signed int          int32_t;
typedef	unsigned long       uint64_t;


void func(int param)	// @violation USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC
{
	char k;		// @violation USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC
	int32_t p;
	uint64_t a;
	unsigned short s;	// @violation USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC
	unsigned int b;	// @violation USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC
	signed l;	// @violation USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC
	char_t aaa;

	int* ptr = 0;		// @violation USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC
	int arr[3] = {1,2,3};		// @violation USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC
	int arr2[3][2] = {1,2,3, 1,2,3};		// @violation USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC

	float f1 = 0.0f;	// @violation USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC
	double f2 = 0.0f;	// @violation USE_TYPEDEF_TYPE_INSTEAD_OF_BASIC
}
