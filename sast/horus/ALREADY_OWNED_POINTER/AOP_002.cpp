#include <memory>

/* AOP_002 - simple case2 */

struct AOP_002_B {
  virtual ~AOP_002_B() {};
};

struct AOP_002_D : AOP_002_B {};

class AOP_002_Test {
public:
  AOP_002_Test(int* v) : val(v) {}
  ~AOP_002_Test() {
    if(val != 0) {
      delete val;
    }
  }

  int* getValue() { return val; }

private:
  int* val;
};

int AOP_002_function1(std::shared_ptr<AOP_002_D> derived) {
  return derived.use_count();
}

int AOP_002_function2(int flag) {
  std::shared_ptr<AOP_002_B> poly(new AOP_002_D);


  AOP_002_Test obj(new int(15));
  
  if(flag > 10) {
    AOP_002_function1(std::shared_ptr<AOP_002_D>(dynamic_cast<AOP_002_D*>(poly.get()))); //@violation ALREADY_OWNED_POINTER
  }
  else {
    int* check = obj.getValue();
    return 0;
  }

  return 0;
}
