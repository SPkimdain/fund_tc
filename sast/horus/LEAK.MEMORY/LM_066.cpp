#include <vector>

/* LM_066 - assign twice - same function */

int LM_066_function1(int flag, std::vector<int*>& arr, int flag2) {
  int* value = 0;
  
  value = new int(10);
  *value = 10;
  int check = 0;
  
  if(flag > 10) {
    if(flag2 > 1) {
     arr.push_back(value);
    }
    else {
      check++;
    }
    value = new int(20);
  } 
  
  delete value;
  
  return 0;
} //@violation LEAK.MEMORY

