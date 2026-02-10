//@checker MINIMISE_MIXING_OF_ITERATOR
#include <vector>

using namespace std;

typedef vector<int> IntVector;
typedef IntVector::iterator Iter;
typedef IntVector::const_iterator CIter;

int MMOITER_001_function(Iter i, CIter ci) { //@violation MINIMISE_MIXING_OF_ITERATOR
  if(i==ci) { 
    return 1; 
  }
  
  return 0;
}
