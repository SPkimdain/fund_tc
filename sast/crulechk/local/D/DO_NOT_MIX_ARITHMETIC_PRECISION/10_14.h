//@checker DO_NOT_MIX_ARITHMETIC_PRECISION

class DoNotMixArthmetic
{
public:
	DoNotMixArthmetic()
	{
		field = 10;
	}
	int getInt()
	{
		return field + 5;
	}

	float getFloat()
	{
		return field2 + 1.0F;
	}

	void checkFunc();
	int field;
	float field2;
};
