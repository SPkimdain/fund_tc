//@checker DO_NOT_DECLARED_INLINE_WITHIN_CLASS_DECLARATION

using namespace std;

class WrongClass
{
public:
	WrongClass() //@violation DO_NOT_DECLARED_INLINE_WITHIN_CLASS_DECLARATION
	{
		x = 10;
	}

	void bar() //@violation DO_NOT_DECLARED_INLINE_WITHIN_CLASS_DECLARATION
	{

	}

	inline void foo();

private:
	int x;
};

inline void WrongClass::foo()
{
	int y = x + 10;
	//cout << y << endl;
}


int main()
{
	WrongClass wc;
	wc.bar();
	wc.foo();
	return 1;
}
