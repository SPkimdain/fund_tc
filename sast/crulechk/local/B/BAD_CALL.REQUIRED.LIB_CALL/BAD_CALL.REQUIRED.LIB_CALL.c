// @checker BAD_CALL.REQUIRED.LIB_CALL

// Dummy functions
extern void LB_call_WLC_exit() {};
extern void LB_call_WLC_need() {};

void Func() { // @violation BAD_CALL.REQUIRED.LIB_CALL
	LB_call_WLC_exit();
	
	// Do something ...
	// LB_call_WLC_need() missing
}

int main()
{
	return 0;
}