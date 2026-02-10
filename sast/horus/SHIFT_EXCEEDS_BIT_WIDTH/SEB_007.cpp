
/* SEB_007 - class member */

class SEB_007_class {
public:
  SEB_007_class(unsigned char d) : data(d), offset(2) {}

  void setOffset(int off) {
    offset = off;
  }

  int getOffset() { return offset; }

  unsigned char getData() {
    return data;
  }

private:
  unsigned char data;
  int offset;
};

unsigned SEB_007_function(int flag) {
  unsigned char bitData = 0;
  SEB_007_class obj(10);

  if(flag > 10) {
    bitData = obj.getData() << obj.getOffset();
    return bitData;
  }
  else {
    obj.setOffset(8);
    bitData = obj.getData() << obj.getOffset(); //@violation SHIFT_EXCEEDS_BIT_WIDTH      
    return bitData;
  }
}
