// @checker BAD_OPERATION_WHILE_POSIX_LOCK

int pthread_mutex_lock();
int recv();
int pthread_mutex_unlock();

void func()
{
	int result = pthread_mutex_lock();

	if (result != 0) {
	/* Handle Error */
	}

	result = recv();	// @violation BAD_OPERATION_WHILE_POSIX_LOCK

	if (result < 0) {
	/* Handle Error */
	}

	/* ... */
	result = pthread_mutex_unlock();
	if ( result != 0) {
	/* Handle Error */
	}
}
