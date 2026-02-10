// @checker PTR_EXCEED_TWO_LEVELS

typedef unsigned char* UCHARPTR;
typedef int	SINT_32;

struct s{
	char *s1;
	char **s2;
	char ***s3; // @violation	PTR_EXCEED_TWO_LEVELS
};

int** foo1;
SINT_32*** foo2;	// @violation	PTR_EXCEED_TWO_LEVELS

int*** (**pfunc1)();	// @violation	PTR_EXCEED_TWO_LEVELS
int** (***pfunc2)();	// @violation	PTR_EXCEED_TWO_LEVELS

void func(int ** p_var3, int *** p_var4)	// @violation	PTR_EXCEED_TWO_LEVELS
{
	UCHARPTR * ptr1;
	UCHARPTR * const * const ptr2 = 0;	// @violation	PTR_EXCEED_TWO_LEVELS
	UCHARPTR ** ptr3;	// @violation	PTR_EXCEED_TWO_LEVELS
	

	struct s *ps1;
	struct s **ps2;
	struct s ***ps3; // @violation	PTR_EXCEED_TWO_LEVELS

	int** bar1;
	int*** bar2;  // @violation	PTR_EXCEED_TWO_LEVELS
	int* bar3;
}
