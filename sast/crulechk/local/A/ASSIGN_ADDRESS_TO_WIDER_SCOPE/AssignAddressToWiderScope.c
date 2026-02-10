//@checker ASSIGN_ADDRESS_TO_WIDER_SCOPE

static int* global_ptr;

void AssignAddressToWiderScope()
{
	int a = 10;
	global_ptr = &a;	//@violation	ASSIGN_ADDRESS_TO_WIDER_SCOPE
}