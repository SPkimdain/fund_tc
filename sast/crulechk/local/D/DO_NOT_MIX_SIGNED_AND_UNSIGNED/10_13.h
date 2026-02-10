//@checker DO_NOT_MIX_SIGNED_AND_UNSIGNED

class DoNotMix
{
public:
	DoNotMix()
	{
		field = 10;
	}
	unsigned int getField()
	{
		return field + 5;
	}

	void checkFunc();
	unsigned int field;
};
