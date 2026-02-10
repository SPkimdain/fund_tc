// @checker BAD_WHITESPACE.POINTER

#define PTR(a) * a

int *global_a;
int* global_b;                 // @violation BAD_WHITESPACE.POINTER
int * global_c;                // @violation BAD_WHITESPACE.POINTER


static int *static_global_a;
static int* static_global_b;              // @violation BAD_WHITESPACE.POINTER
static int * static_global_c;             // @violation BAD_WHITESPACE.POINTER

int main ()
{
	int *a;
    int* b;					// @violation BAD_WHITESPACE.POINTER
    int * c;				// @violation BAD_WHITESPACE.POINTER
    int PTR(d);				
	char encrypt_buf [4000L * 3 + 1];
	char encrypt_buf2 [4000L * 2 + 1];
	
	return 0;
}
