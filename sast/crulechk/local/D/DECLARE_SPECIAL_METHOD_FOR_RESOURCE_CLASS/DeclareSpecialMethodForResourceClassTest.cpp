//@checker DECLARE_SPECIAL_METHOD_FOR_RESOURCE_CLASS

class Test1 //@violation DECLARE_SPECIAL_METHOD_FOR_RESOURCE_CLASS
{
public:

	//It has not a copy constructor and a copy assignment operator

private:
	int x;
	int *px; //@b-violation DECLARE_SPECIAL_METHOD_FOR_RESOURCE_CLASS
};

class Test2 //@violation DECLARE_SPECIAL_METHOD_FOR_RESOURCE_CLASS
{
public:
	Test2( const Test2& inst )
	{
		x = inst.x;
		px = inst.px; //need to deep copy
	}
	
	//It has not a copy assignment operator
private:
	int x;
	int *px; //@b-violation DECLARE_SPECIAL_METHOD_FOR_RESOURCE_CLASS
};

class Test3 //@violation DECLARE_SPECIAL_METHOD_FOR_RESOURCE_CLASS
{
public:
	const Test3& operator =( const Test3& rhs )
	{
		x = rhs.x;
		px = rhs.px;
		return *this;
	}
	
	//It has not a copy constructor
private:
	int x;
	int *px; //@b-violation DECLARE_SPECIAL_METHOD_FOR_RESOURCE_CLASS
};

class Test4 //@violation DECLARE_SPECIAL_METHOD_FOR_RESOURCE_CLASS
{
public: 
	Test4( const Test4& inst )
	{
		x = inst.x;
		px = inst.px; //need to deep copy
	}
	~Test4()
	{
		releaseResources(); //complex destructor
	}

private:
	int x;
  int *px;

	void releaseResources() {}
};


class Test5
{
public:
	Test5( const Test5& inst )
	{
		x = inst.x;
	}
private:
	int x;
	//no pointer member varaible
};

int main()
{
	return 1;
}

