//@checker USE_SUFFIXES_FOR_FLOAT_CONSTANT
//@checker USE_SUFFIXES_FOR_INTEGER_CONSTANT
const unsigned int a = 2U;
const unsigned int b = 2u;      //Non-compliant ? //@violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
const int c = 2L;
const int d = 2l;               //Non-compliant ? //except-violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
const unsigned long e = 2UL;
const unsigned long f = 2Ul;    //Non-compliant ? //@violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
const unsigned int g = 0x12bU;				
const unsigned int h = 0x12bu;  //Non-compliant			//TP INTEGER //@violation USE_SUFFIXES_FOR_INTEGER_CONSTANT
const float m = 1.2F;           
const float n = 2.4l;           //Non-compliant			//TP FLOAT //@violation USE_SUFFIXES_FOR_FLOAT_CONSTANT
