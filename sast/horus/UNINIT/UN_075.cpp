#pragma warning(disable : 4700)

/* UN_075 - nested struct initialize */
struct UN_075_Struct {
  int value;
  void* matchData[3];
};

class UN_075_Class {
public:
  void UN_075_function() {
    UN_075_Struct str = { 1, {this, this, this} };
    
    void* ptr = str.matchData[1]; //It's ok.
  }
};


void UN_075_function3() {
  UN_075_Class obj;
  obj.UN_075_function();

  int a;
  int b = 0;
  b = a; //@violation UNINIT
}
