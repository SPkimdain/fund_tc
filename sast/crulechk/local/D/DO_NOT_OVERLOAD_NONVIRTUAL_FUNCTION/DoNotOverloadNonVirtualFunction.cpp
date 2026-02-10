//@checker DO_NOT_OVERLOAD_NONVIRTUAL_FUNCTION
class Base
{
  public:
    void foo() {}
};
class Derived : public Base
{
  public:
    void foo() {}	//@violation DO_NOT_OVERLOAD_NONVIRTUAL_FUNCTION
};
