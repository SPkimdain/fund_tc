#include <stdexcept>

/* LM_022 - failed dynamic cast(reference). */
using namespace std;

namespace LM_022_Namespace {
class LM_022_Base {
public:
  virtual void function();
};

class LM_022_Derived : public LM_022_Base {
public:
  virtual void function();
};

void LM_022_Base::function() {
  int x = 0;
}

void LM_022_Derived::function()
{
  int x = 0;
}

void LM_022_function1(bool flag)
{
  LM_022_Base* pb = 0;
  if(flag == true)
  {
    pb = new LM_022_Base;
  }
  else
  {
    pb = new LM_022_Derived;
  }

  /* flag가 true일 경우 exception이 발생함 */
  // pb(LM_022_Base object) is leaked.
  LM_022_Derived& pd = dynamic_cast<LM_022_Derived&>(*pb); //@violation LEAK.MEMORY

  delete pb;
}

}

