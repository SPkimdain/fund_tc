
/* DBZ_026 - destructor */
class DBZ_026_Class{
public:
  DBZ_026_Class() : value(0) {}
  ~DBZ_026_Class() {
    int ret = 1000 / (value - 100); // DIV_BY_ZERO
  }
  
  void setValue(int arg) {
    value = arg;
  }

private:
  int value;
};

void DBZ_026_function() {
  DBZ_026_Class* obj = new DBZ_026_Class;
  obj->setValue(100);
  delete obj; //@violation DIV_BY_ZERO
}
