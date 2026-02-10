//@checker DO_NOT_REDEFINE_ERRNO

extern int errno; //@violation DO_NOT_REDEFINE_ERRNO

int func( int x )
{
	return x+10;
}
