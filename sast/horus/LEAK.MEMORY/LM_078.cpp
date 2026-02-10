#include <map>
#include <string>
#include <stdlib.h>

/* LM_078 - assign operator. */
typedef std::map<std::string, int*> LM_078_Map;

class LM_078_Class {
public:
  LM_078_Class() : filter(), count(0) {}

  int LM_078_function1(std::string& str) {
    filter[str] = new int(10);
    
    count++;
    
    return 0;
  }

  ~LM_078_Class() {
    for(LM_078_Map::iterator iter = filter.begin(), end = filter.end();
      iter != end; ++iter) {
      delete iter->second;
    }
  }

private:
  LM_078_Map filter;
  int count;
};


void LM_078_function3() {
  int * ptr = (int*)malloc(4);
} //@violation LEAK.MEMORY
