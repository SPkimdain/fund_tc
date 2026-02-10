
/* TOS_006 - singleton pattern */
class TOS_006_Class {
public:
  static TOS_006_Class& getInstance() {
    static TOS_006_Class instance;
    return instance;
  }
  void setIndex(int _index) {
    index = _index;
  }

  void printValue() {
    arr[index] = 10; 
  }

private:
  TOS_006_Class() {}
  ~TOS_006_Class() {}

  int arr[10];
  int index;
};

void TOS_006_function() {
  TOS_006_Class& obj = TOS_006_Class::getInstance();
  obj.setIndex(5);
  
  obj.printValue(); //It's ok.

  obj.setIndex(20);

  obj.printValue(); //@violation TYPE_OVERRUN.STATIC

}

