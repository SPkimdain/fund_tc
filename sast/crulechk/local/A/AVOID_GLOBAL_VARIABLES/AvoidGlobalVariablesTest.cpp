//@checker AVOID_GLOBAL_VARIABLES

int gVal; // @violation AVOID_GLOBAL_VARIABLES

namespace
{
	int spaceVal;
};

class TEST
{
public:
	int memberVal;
};

int main()
{
	int funcVal;
}

