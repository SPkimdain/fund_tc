//@checker WRITE_VIRTUAL_DTOR_FOR_BASE_CLASS

class Base //@violation WRITE_VIRTUAL_DTOR_FOR_BASE_CLASS
{
};

class Base2 //@violation WRITE_VIRTUAL_DTOR_FOR_BASE_CLASS
{
public: 
	~Base2(); //@b-violation WRITE_VIRTUAL_DTOR_FOR_BASE_CLASS
};

class Derived : public Base 
{ 
public: 
	~Derived() {} 
};

class TBase : public Base
{
public:
	virtual ~TBase() {}
};

class TDerived : public TBase
{
public:
	~TDerived() {}
};

class TDerived2 : public TBase, Base2
{
public:
	~TDerived2() {}
};

class TDerived3 : public TDerived // Not Check. it is virtual type(derived from the 'Base')
{
};
