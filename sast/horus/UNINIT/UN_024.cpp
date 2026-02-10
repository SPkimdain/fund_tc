#pragma warning(disable : 4700)

/* UN_024 - constructor */
class UN_024_Class{
public:
  UN_024_Class() {
    value1 = 100;
    value2 = 100;
    
  }
  void addValue1(int arg) {
    value1 += arg; //It's ok.
  }

  void addValue2(int arg) {
    value2 += arg; 
  }

private:
  int value1;
  int value2;
};

void UN_024_function() {
  UN_024_Class obj;
  int value = 10;
  int value2;
  obj.addValue1(value);
  obj.addValue2(value2);	//@violation UNINIT
}
