// @checker USE_BRACE_MULTI_DIMENSION_ARRAY_INIT

typedef signed int sint32_t;
typedef struct test_struct
{
	int a;
	int b;
}UBMDARRI_001_Struct1;

typedef struct test_struct2
{
	sint32_t x;
	UBMDARRI_001_Struct1 my_struct;
}UBMDARRI_001_Struct2;

UBMDARRI_001_Struct2 g_foo3_1 = {1, 2, 3};	//@violation USE_BRACE_MULTI_DIMENSION_ARRAY_INIT

void UBMDARRI_001_function()
{
	UBMDARRI_001_Struct2 foo3 = {1, {2,3}};
	UBMDARRI_001_Struct2 foo3_1 = {1, 2, 3};	//@violation USE_BRACE_MULTI_DIMENSION_ARRAY_INIT
	UBMDARRI_001_Struct2 foo3_2[2] = {1, 2, 3, 1, 2, 3};		//@violation USE_BRACE_MULTI_DIMENSION_ARRAY_INIT
	UBMDARRI_001_Struct2 foo3_3[2] = {{1, {2,3}}, {1, {2,3}}};
	UBMDARRI_001_Struct2 foo3_4[2] = {1, {2,3}, 1, {2,3}};//@violation USE_BRACE_MULTI_DIMENSION_ARRAY_INIT

	
	int foo[2][3] = { 1, 2, 3, 4, 5, 6 };       //@violation	USE_BRACE_MULTI_DIMENSION_ARRAY_INIT
	int bar[2][3] = { {1, 2, 3}, {4, 5, 6} };
	int foo1[2][3][2] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};	//@violation	USE_BRACE_MULTI_DIMENSION_ARRAY_INIT
	int bar1[2][3][2] = { {{1, 2}, {3, 4}, {5, 6}} , {{7, 8}, {9, 10}, {11, 12}}};	
	UBMDARRI_001_Struct1 foo2[2] = {{1, 2}, {3, 4}};
	UBMDARRI_001_Struct1 bar2[2] = {1, 2, 3, 4};	//@violation	USE_BRACE_MULTI_DIMENSION_ARRAY_INIT
}
