// @checker IMPROPER_RANDOM_USAGE

extern int printf ( const char * format, ... );
extern void srand (unsigned int seed);
extern int rand ();

void foo()
{
	int i=0;
	for (i=0; i<10; i++) {
	  printf("%d, ", rand()); // @violation IMPROPER_RANDOM_USAGE
	}
}
int mytime()
{
	return 123;
}
void bar()
{
	srand(mytime()); /* Create seed based on current time */
	int i=0;
	for (i=0; i<10; i++) {
	  printf("%d, ", rand()); // @violation IMPROPER_RANDOM_USAGE
	}
}
