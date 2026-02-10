#include <Foundation/Foundation.h>
// C
struct S {
  int x;
  int y;
};

void f(struct S s);

void test() {
  struct S s;
  s.x = 1;
  
  f(s); // @violation : passed-by-value arg contain uninitialized data
}
// C
void test1() {
  void (*foo)(void);
  foo(); // @will-violation: function pointer is uninitialized

}
// C
void test2() {
  void (*foo)(void);
  foo = 0;
  foo(); // @will-violation: function pointer is null
}
