//@checker USE_EACH_ACCESS_SPECIFIER_EXACTLY_ONCE

class CExample {
 public:
  /* public member functions, if any */
 protected:
  /* protected member variables and functions, if any */
 private:
  /* private member variables and functions, if any */
};


class Noncompliant { //@violation USE_EACH_ACCESS_SPECIFIER_EXACTLY_ONCE
  //no public
 protected:
 private:
};


class Noncompliant2 { //@violation USE_EACH_ACCESS_SPECIFIER_EXACTLY_ONCE
 public:
 protected:
 private:
 public:
  // two public
};
