//@checker DO_NOT_HIDE_DEREFERENCE_OP_IN_TYPEDEF

typedef int IntValue;

typedef int *PtInt; //@violation DO_NOT_HIDE_DEREFERENCE_OP_IN_TYPEDEF

typedef IntValue *NestedPtInt; //@violation DO_NOT_HIDE_DEREFERENCE_OP_IN_TYPEDEF

int main()
{
	return 0;
}
