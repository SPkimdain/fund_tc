#include <set>

/* LM_072 - set check. */
class LM_072_Class {
public:
  LM_072_Class(std::set<int*>& cont) : value(0), value2(0), container(cont) {
    value = new int(10);
    value2 = new int(20);
  }

  void push() {
    if(value != 0) {
      container.insert(value);
    }
  }

  void push2() {
    if(value2 != 0) {
      container.insert(value2);
    }
  }

private:
  int* value;
  int* value2;
  std::set<int*>& container;
};

/* LM_072 - vector push_back */
void LM_072_function(int flag, std::set<int*>& cont) {
  LM_072_Class obj(cont);

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




