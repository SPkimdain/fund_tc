//@checker DO_NOT_STORE_RETURNED_POINTERS

struct lconv {
  char *decimal_point;
  char *thousands_sep;
  char *grouping;
  char *int_curr_symbol;
  char *currency_symbol;
  char *mon_decimal_point;
  char *mon_thousands_sep;
  char *mon_grouping;
  char *positive_sign;
  char *negative_sign;
  char int_frac_digits;
  char frac_digits;
  char p_cs_precedes;
  char p_sep_by_space;
  char n_cs_precedes;
  char n_sep_by_space;
  char p_sign_posn;
  char n_sign_posn;
};

extern char* getenv (const char* name);
extern struct lconv* localeconv (void);

void func()
{
	char *env = getenv("TEST_ENV"); //@violation DO_NOT_STORE_RETURNED_POINTERS
	
	/* 상수형 변수로 리턴값을 받으면 일단 괜찮음 */
	const char *env2 = getenv("TEST_ENV2");

	struct lconv* lc;
	const struct lconv* clc;

	if (env == 0) {
	/* Handle error */
	}

	if (env2 == 0) {
	/* Handle error */
	}
	
	lc = localeconv(); //@violation DO_NOT_STORE_RETURNED_POINTERS
	
	clc = localeconv();

}

int main()
{
	return 0;
}
