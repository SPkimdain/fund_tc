//@checker UNUSED_PARAMETER

void foo(int a, int b) {	//@violation UNUSED_PARAMETER
	int x = 0;
	x = a + 1;
	/* some code*/
}

void bar(char p1, int p2){//@violation UNUSED_PARAMETER
	int a = 0;
	a = p2 + 1;
}