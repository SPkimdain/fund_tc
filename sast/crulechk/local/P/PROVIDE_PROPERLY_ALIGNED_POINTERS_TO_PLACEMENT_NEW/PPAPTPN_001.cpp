//@checker PROVIDE_PROPERLY_ALIGNED_POINTERS_TO_PLACEMENT_NEW
extern void* operator new(size_t _Size, void* _Where) noexcept;

struct PPAPTPN_001_StructA {
  unsigned long i;
};

struct PPAPTPN_001_StructS {
  unsigned char x;
  unsigned char B[sizeof(PPAPTPN_001_StructA)];
} s;

int PPAPTPN_001_function() {
  PPAPTPN_001_StructA *a = new(&s.B[0]) PPAPTPN_001_StructA; //@violation PROVIDE_PROPERLY_ALIGNED_POINTERS_TO_PLACEMENT_NEW
  unsigned long val = 0xaabbccdd;
  a->i = val;
  return 0;
}
