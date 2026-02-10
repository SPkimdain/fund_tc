// @checker USE_CONTAINERS_OF_POINTER
#include<vector>
#include<map>
#include<set>

using namespace std;

class Example
{
public:
	Example() {}
	void foo()
	{
		int y = 0;
		y++;
		x = y + 10;
	}

private:
	int x;
};

int main()
{
	vector<Example> vecEx; //@violation USE_CONTAINERS_OF_POINTER
	set<Example> setEx; //@violation USE_CONTAINERS_OF_POINTER
	set<string> setString;
	map<string, Example> mapEx; //@violation USE_CONTAINERS_OF_POINTER

	vector< vector<Example> > vecvecEx; //@violation USE_CONTAINERS_OF_POINTER
	vector< vector<int> > vecvecInt;
}
