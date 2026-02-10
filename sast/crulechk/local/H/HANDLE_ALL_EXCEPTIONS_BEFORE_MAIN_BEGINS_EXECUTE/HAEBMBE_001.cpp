//@checker HANDLE_ALL_EXCEPTIONS_BEFORE_MAIN_BEGINS_EXECUTE

struct HAEBMBE_S {
	HAEBMBE_S() noexcept(false) {}
};

extern int HAEBMBE_F() noexcept(false);

static HAEBMBE_S globalS;	//@violation HANDLE_ALL_EXCEPTIONS_BEFORE_MAIN_BEGINS_EXECUTE
int i = HAEBMBE_F();	//@violation HANDLE_ALL_EXCEPTIONS_BEFORE_MAIN_BEGINS_EXECUTE

void HAEBMBE_func_001() {
//...
	return;
}