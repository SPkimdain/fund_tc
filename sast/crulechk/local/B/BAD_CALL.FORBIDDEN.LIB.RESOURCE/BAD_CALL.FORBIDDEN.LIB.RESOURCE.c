// @checker BAD_CALL.FORBIDDEN.LIB.RESOURCE

// Dummy type
struct rlimit {
	int a;
	int b;
};

// Dummy function
extern void getrlimit_FB09(int i, struct rlimit* st) {};

void resource_limit(){  
	struct rlimit rlim;
	getrlimit_FB09(4354, &rlim); // @violation BAD_CALL.FORBIDDEN.LIB.RESOURCE
}

int main ()
{
	return 0;
}