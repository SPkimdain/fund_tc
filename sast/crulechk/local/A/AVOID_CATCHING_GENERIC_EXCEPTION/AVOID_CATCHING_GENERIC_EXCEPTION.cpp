//@checker AVOID_CATCHING_GENERIC_EXCEPTION
class exception {
	
};

void foo(char c)
{
  try 
  {
  
  }
  catch (exception e)	//@violation AVOID_CATCHING_GENERIC_EXCEPTION
  {
  
  }
}

int main() {
	return 0;
}