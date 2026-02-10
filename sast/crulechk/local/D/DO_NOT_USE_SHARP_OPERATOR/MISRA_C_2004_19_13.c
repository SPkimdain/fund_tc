// @checker DO_NOT_USE_SHARP_OPERATOR

/** Regex
 * \s*#define\s*[^#]*
*/

#define DEF0(x) x = x + 1
#define DEF1(x) #x // @violation DO_NOT_USE_SHARP_OPERATOR
#define		 DEF2(x,y) x##y // @violation DO_NOT_USE_SHARP_OPERATOR
 #define 	DEF3( x,y ) (x) + (y) + #x"TEST" ##y // @violation DO_NOT_USE_SHARP_OPERATOR
 
int main()
{

}
