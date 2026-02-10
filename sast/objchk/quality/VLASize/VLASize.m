void test() {
  int y;
  int vla1[y]; // @violation
               // garbage as size
}
void test2() {
  int x = 0;
  int vla2[x]; // @violation
               // zero size
}