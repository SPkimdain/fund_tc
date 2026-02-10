//@checker TESTED_AGAINST_CONSTANT_VALUE

int size(int x)
{
	return x + 10;
}


int main()
{
	int x = 0;
	for(int i = 0; i < size(50); i++) // @violation TESTED_AGAINST_CONSTANT_VALUE
	{
		x += 5;
	}

	int val = 10;

	for(int l = 0; l < val * 2; l++) // @violation TESTED_AGAINST_CONSTANT_VALUE
	{
		x -= 2;
	}

	for(int l = 0; val * 2 > l; l++) // @violation TESTED_AGAINST_CONSTANT_VALUE
	{
		x -= 2;
	}

	for(int j = 0; j< 60; j++)
	{
		x -=1;
	}
  
  for(int j = 0; j < 50 + 60 - 10 / 5; j++) { //It's ok.
    x -= 1;
  }
  
    
  for(int j = 0; j < 50 + 60 - val / 5; j++) { // @violation TESTED_AGAINST_CONSTANT_VALUE
    x -= 1;
  }

}

