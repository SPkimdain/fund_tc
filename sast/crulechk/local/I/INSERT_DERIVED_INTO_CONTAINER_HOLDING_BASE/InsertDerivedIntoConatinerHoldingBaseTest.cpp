//@checker INSERT_DERIVED_INTO_CONTAINER_HOLDING_BASE

#include <vector>

class B {};
class D : public B {};

void foo() {
  std::vector<B> v;
  D obj;
  
  v.push_back(obj);  //@violation INSERT_DERIVED_INTO_CONTAINER_HOLDING_BASE
}
