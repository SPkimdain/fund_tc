// @checker TAG_NAME_SHALL_BE_A_UNIQUE

typedef struct _int64_t {
  int x;
  int y;
} TDEFNSBAU_001_Struct;

void  TDEFNSBAU_001_function() {
  typedef char TDEFNSBAU_001_Struct;
  ...
}

void TDEFNSBAU_001_function2(short TDEFNSBAU_001_Struct) {
  return;
}
