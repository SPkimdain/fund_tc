#include <vector>
#include <string>

/* LM_072 - vector check. */
class LM_071_Class {
public:
  LM_071_Class(std::vector<int*>& cont) : value(0), value2(0), container(cont) {
    value = new int(10);
    value2 = new int(20);
  }

  void push() {
    if(value != 0) {
      container.push_back(value);
    }
  }

  void push2() {
    if(value2 != 0) {
      container.push_back(value2);
    }
  }

private:
  int* value;
  int* value2;
  std::vector<int*>& container;
};

/* LM_071 - vector push_back */
void LM_071_function(int flag, std::vector<int*>& cont) {
  LM_071_Class obj(cont);

  if(flag > 10) {
    obj.push();
    obj.push2();
    return; //It's ok.
  }
  else {
    obj.push();
    return;
    //value2 is leak.
  } //@violation LEAK.MEMORY  
}




