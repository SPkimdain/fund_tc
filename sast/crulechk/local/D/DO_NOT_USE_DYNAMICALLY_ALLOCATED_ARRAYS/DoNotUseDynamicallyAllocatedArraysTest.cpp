//@checker DO_NOT_USE_DYNAMICALLY_ALLOCATED_ARRAYS


int main()
{
	int *x;
	x = new int[100]; //@violation DO_NOT_USE_DYNAMICALLY_ALLOCATED_ARRAYS
	delete[] x;

	int* y = new int[50]; //@violation DO_NOT_USE_DYNAMICALLY_ALLOCATED_ARRAYS
	y[0] = 10;
	delete[] y;

	int* z = new int;
	*z = 10;
	delete z;
}

