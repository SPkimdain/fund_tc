//@checker DO_NOT_MIX_SIGNED_AND_UNSIGNED

#include "10_13.h"

unsigned short foo( unsigned short x, signed short y )
{
	return x + y; //@violation DO_NOT_MIX_SIGNED_AND_UNSIGNED
}

void DoNotMix::checkFunc()
{
	signed int sx = -5;
	unsigned int ux = 4;
	int y = 10;
  
  y = ux; //It's ok - update 20151223

	y = sx + ux; //@violation DO_NOT_MIX_SIGNED_AND_UNSIGNED
	
	if( sx * ux <= 10 ) 
	{
		y++;
	}

	//unsigned 상수
	y = sx + 10U; //It's ok if the option is disabled.

	y = ( this->field + ux ) + sx; //@violation DO_NOT_MIX_SIGNED_AND_UNSIGNED

	y = sx + this->getField(); //@violation DO_NOT_MIX_SIGNED_AND_UNSIGNED
	
	unsigned short usx = 10U;
	signed short ssx = 5;
	

	if( ux > sx ) 
	{
		y++;
	}

	usx = foo( ssx + 10, ssx + 10 ); //not problem
	usx = foo( ssx + 10U, usx + 5U ); //It's ok if the option is disabled.
}


int main()
{
	DoNotMix inst;
	signed int sx = -5;
	unsigned int ux = 4;
	int y = 10;

	y = sx + ux; //@violation DO_NOT_MIX_SIGNED_AND_UNSIGNED
	
	if( sx * ux <= 10 ) 
	{
		y++;
	}

	//unsigned 상수
	y = sx + 10U; //It's ok if the option is disabled.

	y = ( inst.field + ux ) + sx; //@violation DO_NOT_MIX_SIGNED_AND_UNSIGNED

	y = sx + inst.getField(); //@violation DO_NOT_MIX_SIGNED_AND_UNSIGNED
	
	unsigned short usx = 10U;
	signed short ssx = 5;
	

	if( ux > sx ) 
	{
		y++;
	}

	if( ux > 10U &&
		ux > sx ) 
	{
		y++;
	}
  
  bool bValue = false;
  bValue = ux > sx ? true : false;

	usx = foo( ssx + 10, ssx + 10 ); //not problem
	usx = foo( ssx + 10U, usx + 5U ); //It's ok if the option is disabled.

	return 1;
}
