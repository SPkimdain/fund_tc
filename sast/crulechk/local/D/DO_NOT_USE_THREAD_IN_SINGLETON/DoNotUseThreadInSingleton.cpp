//@checker DO_NOT_USE_THREAD_IN_SINGLETON

void pthread_create();
void CreateThread();


class singleton
{
	void test();
};


void singleton::test()
{
	pthread_create(); //@violation DO_NOT_USE_THREAD_IN_SINGLETON
	CreateThread(); //@violation DO_NOT_USE_THREAD_IN_SINGLETON
	 
}
