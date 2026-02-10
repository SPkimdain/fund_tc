//@checker DECLARE_ONE_NAME_ONLY_IN_EACH_TYPEDEF

typedef int* pointer, value; // @violation DECLARE_ONE_NAME_ONLY_IN_EACH_TYPEDEF
typedef int integer, integral, Integral; // @violation DECLARE_ONE_NAME_ONLY_IN_EACH_TYPEDEF
typedef long Long;
typedef float Float; typedef float Float2;

int main()
{
	return 1;
}
