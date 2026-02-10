//@checker DECLARE_READ_ONLY_PARAMETERS

class ClassTest
{
public:
	ClassTest()
	{
		x = 10;
	}
	
	void print()
	{
		//cout << "Class" << endl;
	}
	
	int py;

	const ClassTest& operator=( const ClassTest& lhs )
	{
		x = lhs.x;
		return *this;
	}

private:
	int x;
};

typedef struct _StructTest
{
	int x;
	int y;
} StructTest;

typedef float FLOAT_TYPE;

void func1( ClassTest &ct ) //@violation DECLARE_READ_ONLY_PARAMETERS
{ 
	ct.print();
}

void func2( int x, StructTest &st ) //@violation DECLARE_READ_ONLY_PARAMETERS
{ 
  int y = st.x;
	//cout << st.x << endl;
}

void func3( int x ) //@violation DECLARE_READ_ONLY_PARAMETERS
{ 
int y = x;
	//cout << x << endl;
}

void func4( const ClassTest& ct )
{
  int y = ct.py;
	//cout << ct.py << endl;
}

void func5( int x, const StructTest &st )
{
  int y = st.x;
	//cout << st.x << endl;
}

void func6( const int x )
{
  int y = x;
	//cout << x << endl;
}

void func7( ClassTest &ct )
{
	ClassTest ct2;
	ct = ct2;
	
}

void func8( ClassTest &ct )
{
	ct.py = 10;
}

void func9( int x, StructTest &st )
{
	st.x = 10;
	st.y = 50;
}

void func9( int* const x )
{
	*x = 10;
}

void func10( FLOAT_TYPE ft ) //@violation DECLARE_READ_ONLY_PARAMETERS
{
  float fff = ft;
	//cout << ft << endl;
}

void func11( int x )
{
	x++;
}

int func11( int *var1, int *var2, const int *var3 ) //@violation DECLARE_READ_ONLY_PARAMETERS
{
  *var1 = *var2 - *var3;
  return 0;
}

int func12( int *var1, const int *var2, const int *var3 )
{
  *var1 = *var2 - *var3;
  return 0;
}

int func13( int *var1, int* const var2, const int *var3 )  //@violation DECLARE_READ_ONLY_PARAMETERS
{
  *var1 = *var2 - *var3;
  return 0;
}

int func14( int *var1, const int* const var2, const int *var3 )
{
    *var1 = *var2 - *var3;
    return 0;
}


int main()
{
	ClassTest ct;
	ct.py = 5;

	func1( ct );

	return 1;
}
