/* IU_011 - field value */

class IU_011_Class {
public:
  IU_011_Class() : data(0) {}

  void setValue(unsigned char d) {
    data = d;
  }

  unsigned char getData() { return data; }

private:
  unsigned char data;
};

unsigned char IU_011_function() {
  IU_011_Class obj;

  obj.setValue(10);

  unsigned char x = 1;
  x -= obj.getData(); //@violation INTEGER_UNDERFLOW
  return x;
}

