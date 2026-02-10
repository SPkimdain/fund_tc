//@checker BAD_ARGUMENTS.UMASK

void test (int a)
{
	a;
}
void umask(unsigned int mask)
{
	mask;
}

int main ()
{
	umask(002);
	umask(077);
	umask(100);  //non-octal-integer //@violation BAD_ARGUMENTS.UMASK  
	umask(0100); //argument size over (checker designed to catch  > 077 ) //@violation BAD_ARGUMENTS.UMASK  
	
	test(100);
	test(1111);

	
}