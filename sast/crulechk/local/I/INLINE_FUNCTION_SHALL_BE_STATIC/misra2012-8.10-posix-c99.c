//@checker INLINE_FUNCTION_SHALL_BE_STATIC

inline static int min ( int val1, int val2 );  

inline static int min ( int val1, int val2 )   
{
  return (val1 > val2) ? val2 : val1;
}


inline int max ( int val1, int val2 );  //@violation INLINE_FUNCTION_SHALL_BE_STATIC

inline int max ( int val1, int val2 )    //@violation INLINE_FUNCTION_SHALL_BE_STATIC
{
  return (val1 > val2) ? val1 : val2;
}

int R_8_10 ( void )
{
   int xmax = 5;
   return xmax;
}

/* end of R_08_10.c */
