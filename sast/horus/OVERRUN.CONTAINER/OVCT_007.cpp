#include <vector>

/* OVCT_007 - container operator[] case 1. */
using namespace std;


 void OVCT_007_function(vector<int>& cont){
   cont[-1] = 10;  //@violation OVERRUN.CONTAINER
}
