//@checker BAD_STRUCT_MEMBER_ACCESS
struct BSMACC_Struct {
  int a;
  int b;
};

void Fun_BSMACC_001_function(int x) {
  BSMACC_Struct obj;
  int a;
  a = obj.a;
  a = obj.a;
  a = obj.a; //@violation BAD_STRUCT_MEMBER_ACCESS
}
