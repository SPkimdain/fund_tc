//@checker DO_NOT_CALL_UNLOCK_DIRECTLY_ON_MUTEX

class mutex 
{
public :
	void lock();
	void unlock();
};

void mutex::lock() {
}
void mutex::unlock() {
}

void manipulate_shared_data(mutex &pm) {
  
  pm.lock();	

  pm.unlock(); //@violation DO_NOT_CALL_UNLOCK_DIRECTLY_ON_MUTEX
  
}

int manipulate_shared_data_test() {
	mutex *m = new mutex();
	manipulate_shared_data(*m);
	return 0;
}