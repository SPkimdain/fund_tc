// @checker NO_MORE_THAN_ONE_SHARP_OPERATOR

/** Regex
 * \s*#define\s*[^#]*
*/

#define DEF0(x) x = x + 1
#define DEF1(x) #x
#define		 DEF2(x,y) x##y
#define DEF3(x,y) x#y#x // @violation NO_MORE_THAN_ONE_SHARP_OPERATOR
   #define 	DEF4( x,y ) (x) + (y) + #x"TEST" ##y // @violation NO_MORE_THAN_ONE_SHARP_OPERATOR
 #define 	DEF5( x,y ) (x) + (y) + #x"TEST" ##y # x // @violation NO_MORE_THAN_ONE_SHARP_OPERATOR
 
int main()
{

}
