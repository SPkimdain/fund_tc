/* IO_011 - field value */

class IO_011_Class {
public:
  IO_011_Class() : data(0) {}

  void setValue(unsigned char d) {
    data = d;
  }

  unsigned char getData() { return data; }

private:
  unsigned char data;
};

unsigned char IO_011_function() {
  IO_011_Class obj;

  obj.setValue(255);

  unsigned char x = obj.getData(); 
  x += 10; //@violation INTEGER_OVERFLOW
  
  return x;
}

