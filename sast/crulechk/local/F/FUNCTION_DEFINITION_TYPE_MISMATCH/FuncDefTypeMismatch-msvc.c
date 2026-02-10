//@checker FUNCTION_DEFINITION_TYPE_MISMATCH
typedef int SINT32;
int foo(int a);

int foo(SINT32 a){ //@violation FUNCTION_DEFINITION_TYPE_MISMATCH
  return a+=20;
}

int function(int x, int y, char z);

int function(SINT32 x, SINT32 y, char z)	//@violation FUNCTION_DEFINITION_TYPE_MISMATCH
{
	return x + y + (int)z;	
};
