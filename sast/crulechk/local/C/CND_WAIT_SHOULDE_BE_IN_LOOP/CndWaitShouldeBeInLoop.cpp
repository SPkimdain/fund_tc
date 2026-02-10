//@checker CND_WAIT_SHOULDE_BE_IN_LOOP

class mutex {};
static mutex m;
template <class mutex> class unique_lock
{
public:
	unique_lock(mutex& m) {};
};

class condition_variable 
{
public:	
	template <typename T> void wait(T) {};	
};
static condition_variable condition; 

struct Node 
{
	void *node; 
	struct Node *next; 
};
static Node list;
void consume_list_element(condition_variable &condition) 
{ 
	unique_lock<mutex> lk(m); 
	if (list.next == nullptr) 
	{ 
		condition.wait(lk); //@violation	CND_WAIT_SHOULDE_BE_IN_LOOP
		
	} // Proceed
}

int main() 
{
	return 0;
}
