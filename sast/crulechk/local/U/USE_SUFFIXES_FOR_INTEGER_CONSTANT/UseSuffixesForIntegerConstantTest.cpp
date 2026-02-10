//@checker USE_SUFFIXES_FOR_INTEGER_CONSTANT

void testmacrofunc(long);

typedef unsigned char uint8;
typedef unsigned short uint16;

#define CBRS_ALIGN_ANY 0xF000L
#define WS_CHILD            0x40000000L
#define CBRS_ALIGN_ANY_DEF 0xF000
#define ZERO ((uint8)(0))
#define ONE ((uint8)(1))
#define TWO ((uint8)(2))

  
uint16 addr = ZERO + ONE + TWO; //It's ok.
uint16 addr2 = ZERO + ONE + 104; //@violation USE_SUFFIXES_FOR_INTEGER_CONSTANT

const unsigned int a = 5U;
const unsigned int b = 5u; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
const unsigned int c = 5; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT

const unsigned int castingVar1 = (unsigned int)10; //It's ok.
const unsigned int castingVar2 = (float)10; //It's ok.

const unsigned int afwf312 = 15U;



const long d = 5L;
const long e = 5l; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
const long f = 5; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
const unsigned long g = 5UL;
const unsigned long h = 
	5Ul; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
const unsigned long i = 5; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT

typedef unsigned long TEST;

const TEST t = 5Ul; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT

int main()
{
	testmacrofunc(CBRS_ALIGN_ANY);
	testmacrofunc(CBRS_ALIGN_ANY_DEF); 
	testmacrofunc(WS_CHILD);
	const unsigned int fa = 5U;
	const unsigned int fb = 5u; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
	const unsigned int fc = 5; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
	const long fd = 5L;
	const long fe = 5l; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
	const long ff = 5; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
	const unsigned long fg = 5UL;
	const unsigned long fh = 
		5Ul; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
	const unsigned long fi = 5; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT

	const TEST t = 5Ul; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
	
	const unsigned long fiZero = 0; //Ignore(default option)
  const unsigned int fiOne = 1; //Ignore(default option)
  
  const int testC = 5;
  const unsigned int testA = 40; // @violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
  const unsigned int testB = testA + testC - (1U);

	return 1;
}


