//@checker DECLARE_DESTRUCTOR_FOR_RESOURCE_CLASS


class Test1 //@violation DECLARE_DESTRUCTOR_FOR_RESOURCE_CLASS
{
public:

	Test1( const Test1& inst )
	{
		x = inst.x;
		px = inst.px; //need to deep copy
	}
	
	const Test1& operator =( const Test1& rhs )
	{
		x = rhs.x;
		px = rhs.px;
		return *this;
	}
	
	//It has not a destructor

private:
	int x;
	int *px; //@b-violation DECLARE_DESTRUCTOR_FOR_RESOURCE_CLASS
};

class Test2
{
public:

	Test2( const Test2& inst )
	{
		x = inst.x;
		px = inst.px; //need to deep copy
	}

	~Test2() {}
	
	const Test2& operator =( const Test2& rhs )
	{
		x = rhs.x;
		px = rhs.px;
		return *this;
	}
	
	//It has not a destructor

private:
	int x;
	int *px;
};


class Test3
{
public:

	Test3( const Test3& inst )
	{
		x = inst.x;
	}
	
	const Test3& operator =( const Test3& rhs )
	{
		x = rhs.x;
		return *this;
	}
	
	//It has not a destructor

private:
	int x;
};


int main()
{
	return 1;
}
