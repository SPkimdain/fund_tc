//@checker DECLARE_DESTRUCTOR_USING_NEW
typedef long size_t;
extern void * memcpy ( void * destination, const void * source, size_t num );

struct HasPointer
{
	char kind;
	int *px;
};

class Test1
{
public:
	Test1()
	{
		hp.px = new int[10];
	}
	
	~Test1()
	{
		delete hp.px;
	}

	//It has not a copy assignment operator but do not check this checker.

private:
	int x;
	HasPointer hp;
};


class Test2 //@violation DECLARE_DESTRUCTOR_USING_NEW
{
public:
	Test2()
	{
		hp.px = new int[10]; //@b-violation DECLARE_DESTRUCTOR_USING_NEW
	}

	Test2( int _x )
	{
		hp.px = 0;
		x = _x;
	}

	const Test2& operator =( const Test2& rhs )
	{
		hp.px = rhs.hp.px; //need to deep copy
		return *this;
	}
	
	//It has not a destructor
private:
	int x;
	HasPointer hp;
};

class Test3 //@violation DECLARE_DESTRUCTOR_USING_NEW
{
public:
	Test3( const Test3& inst )
	{
		x = inst.x;
		hp.px = new int[10]; //@b-violation DECLARE_DESTRUCTOR_USING_NEW
		memcpy(hp.px, inst.hp.px, sizeof(int) * 10);
	}

	const Test3& operator =( const Test3& rhs )
	{
		hp.px = rhs.hp.px; //need to deep copy
		return *this;
	}

private:
	int x;
	HasPointer hp;
};

class Test4 { };

int main()
{
	return 1;
}

