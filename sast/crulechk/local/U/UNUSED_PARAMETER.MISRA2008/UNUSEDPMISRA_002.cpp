
//@checker UNUSED_PARAMETER.MISRA2008

#include <vector>

class UNUSEDPMISRA_002_Class
{
public:
  virtual void withUnusedPara(int * para1,
    int unusedpara) = 0;
  virtual void withoutUnusedPara(int * para1,
    std::vector<int>& para2) = 0;

};


class UNUSEDPMISRA_002_Class2 : public UNUSEDPMISRA_002_Class
{
public:
  virtual void withUnusedPara(int * para1, //@violation UNUSED_PARAMETER.MISRA2008
    int unusedpara) 
  {
    *para1 = 1U;
  }
  virtual void withoutUnusedPara(int * para1,
    std::vector<int>& para2)
  {
    *para1 = 1U;
    int ret = 0;
    for (auto&& val : para2) {
      ret += val;
    }
  }

  int nonVirtualFunction(int param1, int param2) {
    return param2 + 100;
  }
};
