// @checker BAD_CALL.REQUIRED.AFTER_CALL

extern void source_call() {};
extern void must_call() {};

int main() 
{
	source_call();	// @violation BAD_CALL.REQUIRED.AFTER_CALL	
	//must_call();
	
	return 0;
}
