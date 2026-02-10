// @checker UNIQUE_VALUE_IN_ENUMERATOR

enum 
{ // @violation UNIQUE_VALUE_IN_ENUMERATOR
	apple,
	melon = 432, //@b-violation UNIQUE_VALUE_IN_ENUMERATOR
	orange = 6, strawberry = 9,  //@b-violation UNIQUE_VALUE_IN_ENUMERATOR
	mango
};

enum 
{ // @violation UNIQUE_VALUE_IN_ENUMERATOR
	fred = 3,
	fblue, 
	fgreen, 
	fyellow = 5 //@b-violation UNIQUE_VALUE_IN_ENUMERATOR
};

enum
{
	red = 3 /* test */, blue = 4, green = 5, yellow = 5
};

enum
{ 
	a = 3, /* It's ok if only use the first value. */
	b,
	c,
	d,
	e,
	f,
	g
};

enum
{
	RED,
	ORANGE,
	YELLOW,
	GREEN,
	BLUE,
	INDIGO,
	VIOLET = INDIGO /* It's ok if option enable. */	
};

int main()
{
	int fruit;
	fruit = orange;
	
	return 1;
}
