//@checker THROW_NULL

int THRNULL_001_function(int flag) {
  int ret = 1;

  if(flag < 0) {
    throw(0); //@violation THROW_NULL
  }

  return ret;
}
