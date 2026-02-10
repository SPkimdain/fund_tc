//@checker RESTRICT_PARAM_VALUE_RANGE
void foo(int p1){
	
}

void func(int p1, int p2, int p3){
	
}

void bar(){
	foo(1);
	foo(-1);	//@violation RESTRICT_PARAM_VALUE_RANGE
	foo(10000);	//@violation RESTRICT_PARAM_VALUE_RANGE
	foo(100);
}