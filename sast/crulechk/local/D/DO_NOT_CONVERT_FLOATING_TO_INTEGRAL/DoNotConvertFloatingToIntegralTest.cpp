//@checker DO_NOT_CONVERT_FLOATING_TO_INTEGRAL

float floatFunc( float x )
{
	return x + 1.0F;
}

int main()
{
	int intVal = 10;
	long longVal = 20L;
	long long longlongVal = 20LL;
	float floatVal = 10.5;
	double doubleVal = 20.5;
	long double longDoubleVal = 30.5;

	intVal = ( int ) floatVal;
	intVal = floatVal; // @violation DO_NOT_CONVERT_FLOATING_TO_INTEGRAL
	doubleVal = ( double ) longVal;
	intVal = ( int ) longVal;
	longlongVal = longDoubleVal; // @violation DO_NOT_CONVERT_FLOATING_TO_INTEGRAL
	longlongVal = ( long long ) longDoubleVal;
	
	unsigned char fooChar = 0;
	
	unsigned char fooChar3 = floatFunc( 1.5F ); //@violation DO_NOT_CONVERT_FLOATING_TO_INTEGRAL
	fooChar3 = (unsigned char)floatFunc( 1.5F ); 
	
	//Complex
		
	fooChar = (unsigned char)( 5 + 99.F );
	fooChar = ( 5 + 99.F ); //@violation DO_NOT_CONVERT_FLOATING_TO_INTEGRAL

}
