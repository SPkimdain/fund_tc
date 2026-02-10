//@checker AT_MOST_ONE_NON_ABSTRACT_BASE_CLASS
class A1 {
  virtual void foo()=0;
};

class A2 {
  virtual void foo2()=0;
};


class B1 {
  void bar();
};

class B2 {
  void zoo();
};

class D1 : private A1{};
class D2 : private A1, private B1{};
class D3 : private A1, private B2{};
class D4 : private B1, private B2{}; //@violation AT_MOST_ONE_NON_ABSTRACT_BASE_CLASS
class D5 : private A1, private B1, private B2{};  //@violation AT_MOST_ONE_NON_ABSTRACT_BASE_CLASS
class D6 : private A1, private A2, private B1{};
