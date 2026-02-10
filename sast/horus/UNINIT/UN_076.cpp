#pragma warning(disable : 4700)

/* UN_076 - uninit with lambda */


void UN_076_function() {
  int a;
  int b;

  auto&& UN_076_lambda = [a](int x) { //@violation UNINIT
    return x + a;
  };

  UN_076_lambda(10);

}
