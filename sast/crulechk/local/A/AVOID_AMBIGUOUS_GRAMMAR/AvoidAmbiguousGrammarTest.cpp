//@checker AVOID_AMBIGUOUS_GRAMMAR

class A
{
public:
	void bar() { int x = 0; }
};


int main()
{
	A a;
	A (b); // @violation AVOID_AMBIGUOUS_GRAMMAR

	int x;
	int (y); // @violation AVOID_AMBIGUOUS_GRAMMAR
	int (z), (k);  // @violation AVOID_AMBIGUOUS_GRAMMAR
	long l, m, (n); // @violation AVOID_AMBIGUOUS_GRAMMAR
	
	A test;
	A (test2); // @violation AVOID_AMBIGUOUS_GRAMMAR
	A test3[100];
	A (   test4[10]   ); // @violation AVOID_AMBIGUOUS_GRAMMAR

	x = 10;
	y = 20;

	return 1;

}
