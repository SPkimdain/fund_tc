//@checker DO_NOT_USE_UNBOUNDED_AGGREGATE_TYPE

int val[] = { 0, 1, 2 }; // @violation DO_NOT_USE_UNBOUNDED_AGGREGATE_TYPE

class Test
{
public:
	int member[10]; // @violation DO_NOT_USE_UNBOUNDED_AGGREGATE_TYPE
};

typedef struct _tag
{
	int structVal[20]; // @violation DO_NOT_USE_UNBOUNDED_AGGREGATE_TYPE
} structTag;

int main()
{
	int valArray[10]; // @violation DO_NOT_USE_UNBOUNDED_AGGREGATE_TYPE
	int* valPArray[20]; // @violation DO_NOT_USE_UNBOUNDED_AGGREGATE_TYPE

	return 1;
}
