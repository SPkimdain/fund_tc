// @checker NAMING_CONVENTION.STRUCTURE

extern void* malloc (size_t size);

#define SIZE_OF_BUFFER 16

typedef struct _A {  // @violation NAMING_CONVENTION.STRUCTURE
  int integer_in_struct;
  char* buffer_in_struct;
  long long llInStruct;
} A;

typedef struct user_account_s {
  int integer_in_struct;
  char* buffer_in_struct;
  long long llInStruct;
} user_account_s;

int g_current_buffer_index;

int variable_test_naming_convention()
{
  char current_buffer = 'a';
  char* userId;

  A invalidStructName;
  A valid_struct_name;

  invalidStructName.integer_in_struct = 0;
  invalidStructName.llInStruct = 10;

  valid_struct_name.buffer_in_struct = (char*)malloc(SIZE_OF_BUFFER*sizeof(char));
  valid_struct_name.llInStruct = 0;

  return 0;
}
