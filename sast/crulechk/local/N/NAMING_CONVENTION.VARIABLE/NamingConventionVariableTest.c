// @checker NAMING_CONVENTION.VARIABLE
#define SIZE_OF_BUFFER 16

extern void* malloc (size_t size);

typedef struct _A {
  int integer_in_struct;
  char* buffer_in_struct;
  long long llInStruct;
} A;

int g_current_buffer_index;
int invalid_global_index; // @violation NAMING_CONVENTION.VARIABLE

int variable_test_naming_convention()
{
  char current_buffer = 'a';
  char* userId; // @violation NAMING_CONVENTION.VARIABLE

  A invalidStructName; // @violation NAMING_CONVENTION.VARIABLE
  A valid_struct_name;

  invalidStructName.integer_in_struct = 0;
  invalidStructName.llInStruct = 10;

  valid_struct_name.buffer_in_struct = (char*)malloc(SIZE_OF_BUFFER*sizeof(char));
  valid_struct_name.llInStruct = 0;
  
  A dummy_4294972688; // It's ok. Ignore the dummy variable for PROFRAME.

  return 0;
}
