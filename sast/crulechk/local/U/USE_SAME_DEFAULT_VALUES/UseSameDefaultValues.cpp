//@checker USE_SAME_DEFAULT_VALUES
class Base
{
  public:
    virtual void goodvFn( int a = 0 );
    virtual void badvFn( int a = 0 ); //@b-violation USE_SAME_DEFAULT_VALUES
};
class Derived : public Base
{
  public:
    virtual void goodvFn( int a = 0 );
    virtual void badvFn( int a = 10 );	//@violation USE_SAME_DEFAULT_VALUES
};

class Base2
{
  public:
    virtual void goodvFn( int a = 0 );
    virtual void badvFn( int a = 0 ); //@b-violation USE_SAME_DEFAULT_VALUES
};
class Derived2 : public Base2
{
  public:
    virtual void goodvFn( int a = 0 );
    virtual void badvFn( int a = 10 );	//@violation USE_SAME_DEFAULT_VALUES
};

class Derived3 : public Derived2
{
  public:
    virtual void goodvFn( int a = 0 );
    virtual void badvFn( int a = 0 );	// OK
};

class Derived4 : public Derived3
{
  public:
    virtual void goodvFn( int a = 0 );
    virtual void badvFn( int a = 4 ); //@violation USE_SAME_DEFAULT_VALUES
};


void bar();

void foo( Derived& obj )
{
    Base& baseObj = obj;
    // Ok - derived and base have the same default value
    //
    baseObj.goodvFn();  // calls Derived::goodvFn with a = 0
    obj.goodvFn();      // calls Derived::goodvFn with a = 0
    // Uses default value from base even though calls derived function

	// calls Derived::badvFn with a = 0
    baseObj.badvFn();  
	// calls Derived::badvFn with a = 10
    obj.badvFn();	
}
