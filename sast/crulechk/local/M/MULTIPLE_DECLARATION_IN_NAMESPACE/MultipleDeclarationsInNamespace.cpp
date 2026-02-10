//@checker MULTIPLE_DECLARATION_IN_NAMESPACE

namespace NS1
{
    void f(short a)
    {
      a += a;
    }
}
using NS1::f;
namespace NS1
{
    void f(int b) //@violation MULTIPLE_DECLARATION_IN_NAMESPACE
    {
      b += b;
    }
}
void bar()
{
  f(0U);
}
