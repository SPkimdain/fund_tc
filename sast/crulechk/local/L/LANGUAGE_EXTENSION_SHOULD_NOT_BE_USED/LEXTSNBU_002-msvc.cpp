//@checker LANGUAGE_EXTENSION_SHOULD_NOT_BE_USED

__declspec(deprecated) int LEXTSNBU_002_function(int x) { //@violation LANGUAGE_EXTENSION_SHOULD_NOT_BE_USED
  int y = 0;
  y += x;

  return y;
}
