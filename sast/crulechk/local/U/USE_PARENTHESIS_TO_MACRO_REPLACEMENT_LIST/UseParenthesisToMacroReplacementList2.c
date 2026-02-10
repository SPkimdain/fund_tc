//@checker USE_PARENTHESIS_TO_MACRO_REPLACEMENT_LIST

#define CAL(a, b) *a = *b + 5 //@violation USE_PARENTHESIS_TO_MACRO_REPLACEMENT_LIST
#define CAL2(a, b ) a = b * 5 //@violation USE_PARENTHESIS_TO_MACRO_REPLACEMENT_LIST
#define CAL3(a,b) ((a) = (b) * 5)


void UseParenthesisToMacroReplacementListTest()
{
	int *b,*c;
	int x,y;
	
	CAL(c,b);
	CAL2(x,y);
	CAL3(x,y);
	
	
}