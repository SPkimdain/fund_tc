//@checker RESTRICT_USE_OF_EXTERN_KEYWORD

// Header file:
const float s = 3.0E8F; // internal linkage constant definition
extern int a; // external linkage object declaration

int foo( int ); // external linkage function declaration

extern int bar( int x ); //@violation RESTRICT_USE_OF_EXTERN_KEYWORD
