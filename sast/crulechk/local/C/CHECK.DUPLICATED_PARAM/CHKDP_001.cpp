//@checker CHECK.DUPLICATED_PARAM
extern void test(const char* str, int x, int y);

void CHKDP_001_function(int p){
  test("bar", p, p); //@violation CHECK.DUPLICATED_PARAM
}
