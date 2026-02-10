// @checker USE_BRACE_MULTI_DIMENSION_ARRAY_INIT

struct UBMDARRI_002_Struct {
  int a;
  int b[5];
};

void UBMDARRI_002_function() {

  UBMDARRI_002_Struct obj1 = { 1, { 2, } }; //It's ok.
  UBMDARRI_002_Struct obj2 = { 1, 2 }; //@violation USE_BRACE_MULTI_DIMENSION_ARRAY_INIT
}
