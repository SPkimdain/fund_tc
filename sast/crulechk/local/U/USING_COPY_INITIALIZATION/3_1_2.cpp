//@checker USING_COPY_INITIALIZATION

extern char * strcpy ( char * destination, const char * source );

class MyString
{
public:
	MyString() {}
	MyString( const char* str ) { strcpy( this->str, str ); }
	MyString( const MyString &rhs ) { strcpy( this->str, rhs.getStr() ); }

	const char* getStr() const { return str; }
private:
	char str[256];
};

class MyClass
{
public:
	MyClass() {}
	MyClass( int x, int y ) { xx = x; yy = y; }
	MyClass( const MyClass &rhs ) { xx = rhs.xx; yy = rhs.yy; }
private:
	int xx;
	int yy;
};

typedef MyString MYSTRING_TYPE;

int main()
{
	int x = 10;
	MyClass f1 = MyClass( x + 5 - 2, 12 ); //@violation USING_COPY_INITIALIZATION	
	
	MyString a1 = "Hello"; //@violation USING_COPY_INITIALIZATION
	MyString b1 = MyString( "Hello" ); //@violation USING_COPY_INITIALIZATION
	MyString c1;
	MyString d1( "Hello" );

	MyString* g1 = new MyString();	

	MYSTRING_TYPE e1 = "Hello2"; //@violation USING_COPY_INITIALIZATION
	

	return 0;
}
