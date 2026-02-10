//@checker DESTRUCTORS_MUST_NOT_THROW_EXCEPTIONS
using namespace std;
class exception {
};

class someException: public exception
{
 public:
  someException(char* msg) throw() { msg_ = msg; }
  ~someException() throw() {}
  virtual const char* what() const throw()
  {
    return msg_;
  }

 private:
  char* msg_;
};

class SomeClass {
  ~SomeClass();

private:
  bool someCondition;
};


SomeClass::~SomeClass() {
  // normal processing
  if (someCondition) {
    throw someException("something nasty");	//@violation DESTRUCTORS_MUST_NOT_THROW_EXCEPTIONS
  }
}
