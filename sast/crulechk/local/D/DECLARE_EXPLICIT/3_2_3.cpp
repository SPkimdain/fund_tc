//@checker DECLARE_EXPLICIT

#include "3_2_3.h"

DCLEXPLT_001_Class::DCLEXPLT_001_Class( int i, float f, int k )
{

}

void DCLEXPLT_001_function1( DCLEXPLT_001_Class const & ); 

void DCLEXPLT_001_function2() 
{ 
    //bar( 10 ); // compile error must be 'bar( DCLEXPLT_001_Class( 10 ) )' 
    //bar( 0.0 ); // implicit convserion to DCLEXPLT_001_Class 
} 
