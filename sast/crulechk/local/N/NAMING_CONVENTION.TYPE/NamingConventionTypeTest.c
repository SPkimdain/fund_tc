// @checker NAMING_CONVENTION.TYPE

#define SIZE_OF_BUFFER 16

struct user_account_s {
	int a;
};

typedef struct user_account_s user_account_t;
typedef struct user_account_s* user_account_p;
typedef struct user_account_s* user_account_pointer; // @violation NAMING_CONVENTION.TYPE

typedef const char* LPCSTR; // @violation NAMING_CONVENTION.TYPE

int typedef_test_naming_convention()
{
  int       a                   = 10;
  long long l_b                 = 1223213213123;
  char      current_buffer      = 'a';
  LPCSTR    long_pointer_string = "test"; // @violation NAMING_CONVENTION.TYPE

  return 0;
}
