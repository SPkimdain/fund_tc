// @checker BAD_CALL.FORBIDDEN.LIB.TIMER

extern void sleep_FB13(unsigned int uint) {};

void set_sleep_func(){
   // Do something ...
   
   sleep_FB13(150); // @violation BAD_CALL.FORBIDDEN.LIB.TIMER
}

int main ()
{
	return 0;
}