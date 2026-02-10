
/* RL_023 - return local with lambda. */


void RL_023_function() {
  auto&& RL_023_lambda = [](int offset) -> int& {
    int x = 10;

    x += offset;
    return x; //@violation RETURN_LOCAL
  };


  int& ret = RL_023_lambda(10);
  ret++;
}

