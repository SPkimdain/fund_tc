//@checker BAD_CALL.INVALID_ADDRESS.SCANF
extern int scanf ( const char * format, ... );

int BCINVAS_001_function()
{
	int n;
	int *p;
	scanf("%d", n);	//@violation BAD_CALL.INVALID_ADDRESS.SCANF
	scanf("%d", p);
	scanf("%d", &n);

  return 0;
}
