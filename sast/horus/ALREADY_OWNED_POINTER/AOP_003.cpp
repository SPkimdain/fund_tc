#include <memory>

/* AOP_003 - simple case3 */

struct AOP_003_B {
  virtual ~AOP_003_B() {};
};

struct AOP_003_D : AOP_003_B {};

int AOP_003_function1(std::shared_ptr<AOP_003_D> derived) {
  return derived.use_count();
}

void AOP_003_function2(int flag) {
  AOP_003_B* b = new AOP_003_D;
  std::shared_ptr<AOP_003_B> poly(b);

  if(flag > 10) {
    AOP_003_function1(std::shared_ptr<AOP_003_D>(dynamic_cast<AOP_003_D*>(poly.get()))); //@violation ALREADY_OWNED_POINTER
  }

  return;
}
