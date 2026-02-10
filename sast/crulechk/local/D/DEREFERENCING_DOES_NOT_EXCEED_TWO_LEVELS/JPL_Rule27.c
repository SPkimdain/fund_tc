// @checker DEREFERENCING_DOES_NOT_EXCEED_TWO_LEVELS

void main()
{		
	int ***a;
	int **b;
	int *c;
	int d = 1;
	int e, f, g, h;

	c = &d;
	b = &c;
	a = &b;

	e = ***a; // @violation	DEREFERENCING_DOES_NOT_EXCEED_TWO_LEVELS
	e = *(*(*a)); // @violation	DEREFERENCING_DOES_NOT_EXCEED_TWO_LEVELS
	f = **b;
	g = *c;
	h = d;

	***a = 5; // @violation	DEREFERENCING_DOES_NOT_EXCEED_TWO_LEVELS
	**b = 4;
	*c = 3;
}