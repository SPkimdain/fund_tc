//@checker DO_NOT_TYPEDEF_ARRAYTYPE

typedef int ARRAY_TYPE[ 10 ]; // @violation DO_NOT_TYPEDEF_ARRAYTYPE

void foo ()
{
	int* array = new ARRAY_TYPE; // calls new[]
	delete[] array; // should be delete[] - confused
}

int main()
{
	return 1;
}