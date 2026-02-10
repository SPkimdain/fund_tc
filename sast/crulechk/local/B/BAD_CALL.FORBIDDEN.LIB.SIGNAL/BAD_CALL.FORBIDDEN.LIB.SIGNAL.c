// @checker BAD_CALL.FORBIDDEN.LIB.SIGNAL

#define SIGINT 0
// Dummy function
extern void signal_FB10(int i, void(*ptr)()) {};
extern void handler() {};

void signal_handler(){
	signal_FB10(SIGINT, handler); // @violation BAD_CALL.FORBIDDEN.LIB.SIGNAL
}

int main () 
{
	return 0;
}
