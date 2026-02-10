//@checker MAKE_PREDICATES_PURE_FUNCTIONS
#include <algorithm>
#include <vector>

using namespace std;

class MPREDPF_001_BadPred {
public:
  bool operator()(const int& ) {
    return ++count == 5; 
  }
private:
  int count;
};

bool MPREDPF_001_check(vector<int>& vec) { 
  return find_if(vec.begin(), vec.end(), MPREDPF_001_BadPred()) != vec.end(); //@violation MAKE_PREDICATES_PURE_FUNCTIONS
}

