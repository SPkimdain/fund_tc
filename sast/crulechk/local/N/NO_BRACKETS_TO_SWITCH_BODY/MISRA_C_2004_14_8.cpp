//@checker NO_BRACKETS_TO_SWITCH_BODY

typedef enum Seasons
{
  spring,
  summer,
  autumn,
  winter
} Seasons;


void static_428(Seasons season)
{
  unsigned int weather_score;
 

}

int main()
{
	//Compile Error.
	

	int x = 0;
	switch (x)
	{
	case 1:
		break;
	default:
		break;
	}

	int y = 10;

	switch (x); //@violation NO_BRACKETS_TO_SWITCH_BODY

	switch (x) default: x = 10; //@violation NO_BRACKETS_TO_SWITCH_BODY

	switch (x) case 10: x = 5; //@violation NO_BRACKETS_TO_SWITCH_BODY
}
