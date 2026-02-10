//@checker DO_NOT_USE_THROW_IN_CTOR_OR_DTOR
class C
{
	public :
	C()
	{
		throw (0); //@violation DO_NOT_USE_THROW_IN_CTOR_OR_DTOR
	}
	~C()
	{
		throw (0); //@violation DO_NOT_USE_THROW_IN_CTOR_OR_DTOR
	}
};

C c;

int main (int argc, char ** argv)
{
	try{
		return 0;
	}
	catch ( ... )
	{
		return 0;
	}
}