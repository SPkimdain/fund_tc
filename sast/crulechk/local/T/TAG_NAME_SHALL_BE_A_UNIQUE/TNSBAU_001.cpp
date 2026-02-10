// @checker TAG_NAME_SHALL_BE_A_UNIQUE

class TNSBAU_001_class {
public:
  TNSBAU_001_class() { //It's ok.
    value = 0;
  }

  ~TNSBAU_001_class() { //It's ok.
    //do something
  }
  
private:
  int value;
};

void TNSBAU_001_WrapFunction() {
  
  enum TNSBAU_001_class { //@violation TAG_NAME_SHALL_BE_A_UNIQUE
    TT_001,
    TT_002
  };

  int x = 0;
  x++;
  return;
}
