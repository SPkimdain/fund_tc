//@checker NAME_SHOULD_NOT_START_WITH_UNDERSCORE

int _global;  //@violation NAME_SHOULD_NOT_START_WITH_UNDERSCORE
int global;

void _foo();  //@violation NAME_SHOULD_NOT_START_WITH_UNDERSCORE
void bar();

void foo(int _param);   //@violation NAME_SHOULD_NOT_START_WITH_UNDERSCORE
void zoo(int param);


void foo2(int _param) //@violation NAME_SHOULD_NOT_START_WITH_UNDERSCORE
{
	//Do something
}   
void _zoo2(int param) //@violation NAME_SHOULD_NOT_START_WITH_UNDERSCORE
{
	//Do something
}	
