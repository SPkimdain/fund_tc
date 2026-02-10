
/* DBZ_028 - singleton pattern */
class DBZ_028_Class {
public:
  static DBZ_028_Class& getInstance() {
    static DBZ_028_Class instance;
    return instance;
  }
  void setValue(int x) {
    value = x;
  }

  void printValue() {
    int ret = 1000 / value; // DIV_BY_ZERO
  }

private:
  DBZ_028_Class() {}
  ~DBZ_028_Class() {}

  int value;
};

void DBZ_028_function() {
  int x = 50;
  DBZ_028_Class& obj = DBZ_028_Class::getInstance();
  obj.setValue(x);
  
  obj.printValue(); //It's ok.

  obj.setValue(x - 50);

  obj.printValue(); //@violation DIV_BY_ZERO
}

