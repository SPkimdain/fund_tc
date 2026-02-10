//@checker CALL_VIRTUAL_WITHOUT_QUALIFIER_IN_CTOR_DTOR
class Base
{
public:
	virtual ~Base()=0;
	virtual void func();
protected:
	Base();
	Base(const Base&);
	Base& operator=(const Base&);
};

class Sub : public Base
{
public:
	Sub() : Base() {}
	virtual ~Sub();
	virtual void func();
private:
	Sub(const Sub&);
	Sub& operator=(const Sub&);
};

Base::Base()
{
	func();	//@violation CALL_VIRTUAL_WITHOUT_QUALIFIER_IN_CTOR_DTOR
	Base::func();
}

void Base::func()
{
}

void Sub::func()
{
}

int main()
{
	return 0;

}