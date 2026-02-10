
/* DBZ_025 - constructor, initializer list */
class DBZ_025_Class{
public:
  DBZ_025_Class() : value(100), value2(200) {}
  int div1(int arg) {
    return 1000 / (value - arg);
  }

  int div2(int arg) {
    return 1000 / (value2 - arg); // DIV_BY_ZERO
  }

private:
  int value;
  int value2;
};

void DBZ_025_function() {
  int ret = 0;
  DBZ_025_Class obj;
  ret = obj.div1(200);
  ret = obj.div2(200); //@violation DIV_BY_ZERO
}
