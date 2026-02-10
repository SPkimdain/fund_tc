
/* TUDS_006 - singleton pattern */
class TUDS_006_Class {
public:
  static TUDS_006_Class& getInstance() {
    static TUDS_006_Class instance;
    return instance;
  }
  void setIndex(int _index) {
    index = _index;
  }

  void printValue() {
    arr[index] = 10; 
  }

private:
  TUDS_006_Class() {}
  ~TUDS_006_Class() {}

  int arr[10];
  int index;
};

void TUDS_006_function() {
  TUDS_006_Class& obj = TUDS_006_Class::getInstance();
  obj.setIndex(5);
  
  obj.printValue(); //It's ok.

  obj.setIndex(-1);

  obj.printValue(); //@violation TYPE_UNDERRUN.STATIC

}

