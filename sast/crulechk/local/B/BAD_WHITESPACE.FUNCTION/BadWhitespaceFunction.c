// @checker BAD_WHITESPACE.FUNCTION

#define TEST foo ( ) {}

void nh_2_4_2_7_2_ex1( ) {}
void nh_2_4_2_7_2_ex2 ( ) {}      // @violation BAD_WHITESPACE.FUNCTION
void nh_2_4_2_7_2_ex3             // @violation BAD_WHITESPACE.FUNCTION
( ) {}


TEST
