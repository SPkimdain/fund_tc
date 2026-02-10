//@checker DECLARE_NON_MEMBER_GENERIC_FUNC_IN_UNASSOCIATED_NAMESPACE

template <typename T>
class B
{
public:
  B& operator+(long  rhs) {
    return *this;
  }

  void f()
  {
    /* 개발자는 해당 코드에서 클래스 내부의 operator+ 함수, 즉 위에 있는 함수가 
       호출되길 원하지만 실제로는 ns::operator+가 호출된다. 그러므로 문제가 될 수 있음. */
    *this + 10;
  }
};

namespace NS
{
  class A {
  public:
  };

  template<typename T>
  int operator+(T& lhs , int rhs) {   //@violation DECLARE_NON_MEMBER_GENERIC_FUNC_IN_UNASSOCIATED_NAMESPACE
    return rhs;
  }
}


int main() {
  B<NS::A> obj;
  obj.f();
}

