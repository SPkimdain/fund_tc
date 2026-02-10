// @checker DEFINE_OBJECT_AT_BLOCK_SCOPE

int g_a = 0; 
int g_b = 1;
int g_c = 2; // @violation	DEFINE_OBJECT_AT_BLOCK_SCOPE

void foo()
{
	int x;
	x = g_a; // Count : 1
	x = x + g_b; // Count : 1
}

void bar()
{
	int y = 1;
	g_a = y; // Count : 2;
	g_b = g_a ; // Count : 2 / 2
}

void main()
{
	int z = g_c; // Count : 1
	g_c = z + 3;
	g_a = g_c; // Count : 3;
}
