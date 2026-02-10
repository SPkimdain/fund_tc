// @checker REPRESENTATION_SIGNED_INTEGER
extern int scanf ( const char * format, ... );

int foo()
{
	int value;
 
	if (scanf("%d", &value) == 1) {
	  if (value & 0x1 != 0) {	//@violation	REPRESENTATION_SIGNED_INTEGER
		/* do something if value is odd */
	  }
	}
	if (scanf("%d", &value) == 1) {
	  if (value % 2 != 0) {
		/* do something if value is odd */
	  }
	}
	return 0;
}
