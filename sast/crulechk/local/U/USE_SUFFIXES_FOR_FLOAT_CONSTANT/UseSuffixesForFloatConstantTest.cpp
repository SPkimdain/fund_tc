//@checker USE_SUFFIXES_FOR_FLOAT_CONSTANT

const float PI = 3.1415F;
const long double R = 0.003; // @violation USE_SUFFIXES_FOR_FLOAT_CONSTANT
const long double A = 0.0L;
const long double Z =
	0.0l; // @violation USE_SUFFIXES_FOR_FLOAT_CONSTANT

typedef long double TEST;

const TEST t = 0.0l; // @violation USE_SUFFIXES_FOR_FLOAT_CONSTANT

int main()
{
	const float PI = 3.1415F;
	const long double R = 0.003; // @violation USE_SUFFIXES_FOR_FLOAT_CONSTANT
	const long double A = 0.0L;
	const long double Z = 
		0.0l; // @violation USE_SUFFIXES_FOR_FLOAT_CONSTANT

	const TEST ft = 0.0l; // @violation USE_SUFFIXES_FOR_FLOAT_CONSTANT

	return 1;

}
