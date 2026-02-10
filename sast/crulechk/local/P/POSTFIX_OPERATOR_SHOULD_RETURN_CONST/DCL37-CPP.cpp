// @checker POSTFIX_OPERATOR_SHOULD_RETURN_CONST

class A {
 public:
  A operator++(int);  // @violation POSTFIX_OPERATOR_SHOULD_RETURN_CONST

 private:
  int data;
};


class Compliant {
 public:
  const Compliant operator++(int);

 private:
  int data;
};
