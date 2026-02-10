//@checker MEMORY_COMPARISON_OF_FLOAT_POINT_VALUES 

extern int memcmp(const void* s1, const void* s2, unsigned len);
  
struct S {
  int i;
  float f;
};
  
int are_equal(const struct S *s1, const struct S *s2) {
  if (!s1 && !s2)
    return 1;
  else if (!s1 || !s2)
    return 0;
  return 0 == memcmp(s1, s2, sizeof(struct S)); //@violation MEMORY_COMPARISON_OF_FLOAT_POINT_VALUES 
}