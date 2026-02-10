//@checker MAKE_COPYING_EFFICIENT_FOR_OBJECT

#include <vector>
#include <map>
#include <list>

using namespace std;

class ImplicitCopyingClass
{
public:
	ImplicitCopyingClass() {}

private:
	int x;
};

class ParticleCopyingClass
{
public:
	ParticleCopyingClass() {}
	ParticleCopyingClass( ParticleCopyingClass const& rhs ) //It has copy ctor.
	{
		x  = rhs.x;
	}

private:
	int x;
};

class ExplicitCopyingClass
{
public:
	ExplicitCopyingClass() {}
	ExplicitCopyingClass( ExplicitCopyingClass const& rhs ) //It has copy ctor.
	{
		x  = rhs.x;
	}
	ExplicitCopyingClass& operator=( const ExplicitCopyingClass& rhs ) //It has copy assignment.
	{
		x = rhs.x;
	}

private:
	int x;
};

class Base
{
public:
	Base() {}
	Base( Base const& rhs )
	{
		x = rhs.x;
	}
	Base& operator=( const Base& rhs )
	{
		x = rhs.x;
	}

protected:
	int x;
};

class Derived : public Base
{
public:
	Derived() {}
	Derived( Derived const& rhs )
	{
		x = rhs.x;
		y = rhs.y;
	}
	Derived& operator=( const Derived& rhs )
	{
		x = rhs.x;
		y = rhs.y;
	}

private:
	int y;
};

void foo( vector<ImplicitCopyingClass> icc ) //@violation MAKE_COPYING_EFFICIENT_FOR_OBJECT
{
	int z = 0;
	return;
}

typedef vector<ImplicitCopyingClass> VecICC;

int main()
{
	vector<ImplicitCopyingClass> icc; //@violation MAKE_COPYING_EFFICIENT_FOR_OBJECT
	vector<ParticleCopyingClass> pcc; //@violation MAKE_COPYING_EFFICIENT_FOR_OBJECT
	vector<ExplicitCopyingClass> ecc;
	map<int, ImplicitCopyingClass> mIcc; //@violation MAKE_COPYING_EFFICIENT_FOR_OBJECT
	map<int, vector<ImplicitCopyingClass> > mNestedIcc; //@violation MAKE_COPYING_EFFICIENT_FOR_OBJECT

	list<Base> bList;

	VecICC typeIcc; //@violation MAKE_COPYING_EFFICIENT_FOR_OBJECT
	
	return 1;

}

