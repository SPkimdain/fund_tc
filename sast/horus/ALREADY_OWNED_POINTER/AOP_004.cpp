#include <memory>

/* AOP_004 - lambda block */

void AOP_004_function() {
  auto&& p = [](int x) {
    int *i = new int(10);

    std::shared_ptr<int> p1(i);

    std::shared_ptr<int> p2(i); //@violation ALREADY_OWNED_POINTER
  };

  p(10);
}

