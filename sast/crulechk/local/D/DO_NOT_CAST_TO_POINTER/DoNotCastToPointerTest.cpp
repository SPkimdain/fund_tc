//@checker DO_NOT_CAST_TO_POINTER 

typedef int Integer;
typedef Integer* IntegerPtr;

struct Type
{
	int* x;
};

struct Type2
{
	int* arr[10];
};


int main()
{
	Type t = { 0 };
	Type2 t2;
	int xx = 0;
	short x = 5;
	int y = 10;
	short* shortVar = &x;
	int* intVar = &y;	

	Integer* integerVar = &y;
	IntegerPtr integerVar2 = &y;
	const Integer* integerVar3 = &y;

	int* intArr[10] = { 0 };

	shortVar = (short*)intArr[xx]; //@violation DO_NOT_CAST_TO_POINTER

	shortVar = (short*)t2.arr[xx]; //@violation DO_NOT_CAST_TO_POINTER

	shortVar = (short*)t.x; //@violation DO_NOT_CAST_TO_POINTER

	
	shortVar = (short*)intVar; //@violation DO_NOT_CAST_TO_POINTER

	shortVar = (short*)*intVar;

	shortVar = (short*)&x; //@violation DO_NOT_CAST_TO_POINTER
	
	integerVar = (Integer*)shortVar; //@violation DO_NOT_CAST_TO_POINTER
	
	integerVar2 = (IntegerPtr)shortVar;  //@violation DO_NOT_CAST_TO_POINTER

	integerVar3 = (const Integer*)integerVar;

	integerVar3 = integerVar;
}
