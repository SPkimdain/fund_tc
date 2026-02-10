#include <memory>

/* AOP_001 - simple case */

void AOP_001_function() {
  int *i = new int(10);
  std::shared_ptr<int> p1(i);
  
  std::shared_ptr<int> p2(i); //@violation ALREADY_OWNED_POINTER
}
