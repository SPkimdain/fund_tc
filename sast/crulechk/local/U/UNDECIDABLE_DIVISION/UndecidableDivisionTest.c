//@checker UNDECIDABLE_DIVISION
void foo(int p1){
	int a = 100 / p1;	//@violation UNDECIDABLE_DIVISION
}

void bar(){
	const int b = 100;
	int a = 100 / b;
}