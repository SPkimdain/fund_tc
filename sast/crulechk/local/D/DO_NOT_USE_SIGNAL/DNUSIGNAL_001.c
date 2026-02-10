//@checker DO_NOT_USE_SIGNAL

#include <signal.h>


void DNUSIGNAL_handler(int signum)
{
	return;
}

int DNUSIGNAL_001_function()
{
  signal(SIGINT, DNUSIGNAL_handler); //@violation DO_NOT_USE_SIGNAL	

	return 0;
}

