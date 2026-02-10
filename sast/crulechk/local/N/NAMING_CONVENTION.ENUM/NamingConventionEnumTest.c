// @checker NAMING_CONVENTION.ENUM
extern int printf ( const char * format, ... );

int g_test_int;

enum valid_enum_e {ONE, TWO, THREE};
enum invalid_enum {INVAID_ONE, INVAL_TWO, INVAL_THREE} ; // @violation NAMING_CONVENTION.ENUM
enum invalid_tag {invalid_tag, invalid_tag_two, invalid_tag_three} ; // @violation NAMING_CONVENTION.ENUM

int main(int argc, char *argv[])
{
  enum valid_enum_e right_case;
  enum invalid_enum wrong_case;

  right_case = ONE;
  wrong_case = INVAL_THREE;

  printf("right_case: %d\n", right_case);
  printf("wrong_case: %d\n", wrong_case);

  return 0;
}
