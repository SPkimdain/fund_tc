// @checker BAD_CALL.FORBIDDEN.LIB.TP

// Dummy define
#define TPRECVONLY 0
#define NULL 0x00

// Dummy function
extern void tprecv_FB11(int i) {};

void terminate_tp(char * buf){
	if(buf!=NULL) {
		tprecv_FB11(TPRECVONLY); // @violation BAD_CALL.FORBIDDEN.LIB.TP
	}
	
	// Do something...
}

int main ()
{
	return 0;
}