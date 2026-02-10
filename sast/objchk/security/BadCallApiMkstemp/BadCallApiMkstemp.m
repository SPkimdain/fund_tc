void test() {
  mkstemp("XX"); // @violation
  //길이가 6 미만일때.
}