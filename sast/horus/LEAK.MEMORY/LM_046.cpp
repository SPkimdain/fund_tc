
/* LM_046 - object new. */
class LM_046_Class {
public:
  LM_046_Class() : value(-1) {}

  void setValue(int v) { value = v; }
  int getValue() { return value; }
private:
  int value;
};

void LM_046_function(int flag) {
  LM_046_Class* v = 0;
  if(flag > 0) {
    v = new LM_046_Class();
  }

  return;
} //@violation LEAK.MEMORY

