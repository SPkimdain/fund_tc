
/* UN_025 - constructor, initializer list */
class UN_025_Class{
public:
  UN_025_Class() : value1(100) {} /* Missing initialize value2 */
  int getValue1() {
    return value1;
  }

  int getValue2() {
    return value2;
  }

private:
  int value1;
  int value2;
};

void UN_025_function() {
  UN_025_Class obj;
  int ret = 0;
  ret += obj.getValue1(); //It's ok.
  ret += obj.getValue2(); //@violation UNINIT  
}
