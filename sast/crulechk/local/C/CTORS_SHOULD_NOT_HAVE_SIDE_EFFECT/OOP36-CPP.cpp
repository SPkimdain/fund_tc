//@checker CTORS_SHOULD_NOT_HAVE_SIDE_EFFECT
class Test{
public:
	Test& operator=(const Test& rhs)
	{
		x = rhs.x;
	}
private:
	int x;
};

class NoncompliantA {
public:
  NoncompliantA() : value(0) {}
  NoncompliantA(const NoncompliantA& rhs) : value(rhs.value) {
    invocations = invocations + 1;	//@violation CTORS_SHOULD_NOT_HAVE_SIDE_EFFECT
    ++invocations; //@violation CTORS_SHOULD_NOT_HAVE_SIDE_EFFECT
	inst = rhs.inst; //@violation CTORS_SHOULD_NOT_HAVE_SIDE_EFFECT
  }
private:
  int value;
  static int invocations;
  Test inst;
};
 
/* ... */
 
int NoncompliantA::invocations = 0;
 
/* ... */
 
NoncompliantA f() {
  return NoncompliantA();
}
 
/* ... */
 
void b() {
  NoncompliantA a = f();
}




class CompliantA {
public:
  CompliantA() : value(0) {
    invocations = invocations + 1;
    ++invocations;
  }
  CompliantA(const CompliantA& rhs) : value(rhs.value) {}
private:
  int value;
  static int invocations;
};
 
/* ... */
