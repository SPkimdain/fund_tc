
/* ND_079 - nested struct initialize */
struct ND_079_Struct {
  int value;
  void* matchData[3];
};

class ND_079_Class {
public:
  ND_079_Class() : check(10) {}

  void* ND_079_function() {
    ND_079_Struct str = { 1,{ this, this } }; //matchData[2] is null.

    return str.matchData[2];
  }

  int getCheck() { return check; }

private:
  int check;
};


int ND_079_function3(int flag) {
  int ret = 0;
  ND_079_Class obj;
  if(flag > 10) {
    ND_079_Class* ptr2 = (ND_079_Class*)obj.ND_079_function();
    ret = ptr2->getCheck(); //@violation NULL_DEREF
  }
  
  ret++;
  return ret;
}
