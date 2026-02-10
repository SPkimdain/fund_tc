// @checker BAD_CALL.FORBIDDEN.PARAM.NUMBER

extern void LB_call_WA(double d1, double d2, double d3) {};

void Func(const char * x) {	
	LB_call_WA(1.5, 2.3, 12.123); // @violation BAD_CALL.FORBIDDEN.PARAM.NUMBER
	
	// Do something ...
}

int main()
{
	return 0;
}