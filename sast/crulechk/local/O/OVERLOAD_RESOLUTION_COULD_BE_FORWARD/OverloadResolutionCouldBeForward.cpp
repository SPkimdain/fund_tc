//@checker OVERLOAD_RESOLUTION_COULD_BE_FORWARD
//Example from LDRA 546S

/*******************************************************************
 * Standard 546 S : Overload resolution could be forward.
 *******************************************************************/
void func (int pp){}

template <typename T > void proc(T aa )
{
     func(aa); // not compliant
}

void func (unsigned int pp){}

static void static_546( void )
{
}

/*
 *
 * Copyright (c) 2009 Liverpool Data Research Associates
 *
 */
