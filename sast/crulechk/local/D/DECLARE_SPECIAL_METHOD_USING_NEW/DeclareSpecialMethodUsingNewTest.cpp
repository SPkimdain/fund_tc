//@checker DECLARE_SPECIAL_METHOD_USING_NEW
typedef long size_t;
extern void * memcpy ( void * destination, const void * source, size_t num );

struct HasPointer
{
	char kind;
	int *px;
};

class Test1 //@violation DECLARE_SPECIAL_METHOD_USING_NEW
{
public:
	Test1()
	{
		hp.px = new int[10]; //@b-violation DECLARE_SPECIAL_METHOD_USING_NEW
	}
	
	~Test1()
	{
		delete hp.px;
	}

	//It has not a copy assignment operator

private:
	int x;
	HasPointer hp;
};

class Test2 //@violation DECLARE_SPECIAL_METHOD_USING_NEW
{
public:
	Test2()
	{
		hp.px = new int[10]; //@b-violation DECLARE_SPECIAL_METHOD_USING_NEW
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

class Test3
{
public:
	Test3()
	{
		hp.px = new int[10];
	}
	
	~Test3()
	{
		delete hp.px;
	}

	Test3( const Test3& inst )
	{
		x = inst.x;
		hp.px = new int[10];
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

int main()
{
	return 1;
}

