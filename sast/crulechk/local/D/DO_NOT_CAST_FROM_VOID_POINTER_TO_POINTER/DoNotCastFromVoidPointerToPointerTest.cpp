//@checker DO_NOT_CAST_FROM_VOID_POINTER_TO_POINTER 

typedef int Integer;
typedef Integer* IntegerPtr;

struct Type
{
	void* x;
};

struct Type2
{
	void* arr[10];
};


int main()
{
	Type t = { 0 };
	Type2 t2;
	int xx = 0;
	short x = 5;
	int y = 10;
	short* shortVar = &x;
	void* voidPtr = 0;
	const void* voidPtr2 = 0;
	int* intVar = &y;	

	Integer* integerVar = &y;
	IntegerPtr integerVar2 = &y;
	const Integer* integerVar3 = &y;

	void* voidArr[10] = { 0 };

	shortVar = (short*)voidArr[xx]; //@violation DO_NOT_CAST_FROM_VOID_POINTER_TO_POINTER

	shortVar = (short*)t2.arr[xx]; //@violation DO_NOT_CAST_FROM_VOID_POINTER_TO_POINTER

	shortVar = (short*)t.x; //@violation DO_NOT_CAST_FROM_VOID_POINTER_TO_POINTER
	
	integerVar = (Integer*)voidPtr; //@violation DO_NOT_CAST_FROM_VOID_POINTER_TO_POINTER
	
	integerVar2 = (IntegerPtr)voidPtr;  //@violation DO_NOT_CAST_FROM_VOID_POINTER_TO_POINTER

	voidPtr2 = (const void*)voidPtr;

	voidPtr2 = voidPtr;

}
