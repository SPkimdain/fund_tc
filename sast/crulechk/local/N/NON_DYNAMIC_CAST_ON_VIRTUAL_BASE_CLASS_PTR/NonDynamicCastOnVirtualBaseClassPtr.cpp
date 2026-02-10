//@checker NON_DYNAMIC_CAST_ON_VIRTUAL_BASE_CLASS_PTR
class Base
{
public:
	virtual ~Base();
	virtual class Derived *getAsDerived() = 0;
	virtual class Derived1 *getAsDerived1() = 0;
};
class Derived1 : virtual public Base
{
public:
	virtual class Derived1 *getAsDerived1()
	{	return this;}
};


class Derived : public Base
{
public:
	virtual class Derived *getAsDerived()
	{	return this;}
};


void foo(Base *bp, Derived *dp, Derived1 *dp1)
{
	//Compile error dp = static_cast<Derived *>(bp);	//@v NON_DYNAMIC_CAST_ON_VIRTUAL_BASE_CLASS_PTR
	//Compile error dp = (Derived *) (bp);	//@v NON_DYNAMIC_CAST_ON_VIRTUAL_BASE_CLASS_PTR
	dp = reinterpret_cast<Derived *>(bp);	//ok
	dp1 = reinterpret_cast<Derived1 *>(bp);	//@violation NON_DYNAMIC_CAST_ON_VIRTUAL_BASE_CLASS_PTR
}
int main()
{
	return 0;
}
