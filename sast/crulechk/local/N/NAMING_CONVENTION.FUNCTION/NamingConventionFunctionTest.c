// @checker NAMING_CONVENTION.FUNCTION

extern int printf ( const char * format, ... );

#define SIZE_OF_BUFFER 16

const char* get_file_name();
void  set_current_user();
int   checkNamingConvention();
void  addNamingConvention();
int   variable_test_naming_convention();

int variable_test_naming_convention()
{
  int       a              = 10;
  long long l_b            = 1223213213123;
  char      current_buffer = 'a';

  return 0;
}

const char* get_file_name()
{
  return "";
}

void set_current_user()
{
  char userName;
}

int checkNamingConvention()     // @violation NAMING_CONVENTION.FUNCTION
{
  return 0;
}

int main(int argc, char *argv[])
{
  printf("hello\n");

  return 0;
}
