//@checker MUST_CATCH_ALL_EXCEPTION_IN_MAIN

int main() {
  throw 10; //@violation MUST_CATCH_ALL_EXCEPTION_IN_MAIN
  return 0;
}
