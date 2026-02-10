//@checker DO_NOT_USE_RESERVED_IN_MACRO

#define test int


#define while( E ) for ( ;  ( E ) ; ) //@violation DO_NOT_USE_RESERVED_IN_MACRO
#define unless( E ) if ( ! ( E ) )
#define test double

#define ___LINE___ //@violation DO_NOT_USE_RESERVED_IN_MACRO
#define _GUARD_H 1 //@violation DO_NOT_USE_RESERVED_IN_MACRO
#define _BUILTIN_sqrt //@violation DO_NOT_USE_RESERVED_IN_MACRO
#define errno my_errno //@violation DO_NOT_USE_RESERVED_IN_MACRO

int DNURSRVIM_001_function1(int a)
{
	a++;
  a++;
  
  return a * 10;	
}
