// @checker NAMING_CONVENTION.UNION
#define SIZE_OF_BUFFER 16

extern void* malloc (size_t size);

typedef union _A {  // @violation NAMING_CONVENTION.UNION
  int integer_in_union;
  char* buffer_in_union;
  long long llInUnion;
} A;

typedef union user_account_u {
  int integer_in_union;
  char* buffer_in_union;
  long long llInUnion;
} user_account_s;

int g_current_buffer_index;

int variable_test_naming_convention()
{
  char current_buffer = 'a';
  char* userId;

  A invalidUnionName;
  A valid_union_name;

  invalidUnionName.integer_in_union = 0;
  invalidUnionName.llInUnion = 10;

  valid_union_name.buffer_in_union = (char*)malloc(SIZE_OF_BUFFER*sizeof(char));
  valid_union_name.llInUnion = 0;

  return 0;
}
