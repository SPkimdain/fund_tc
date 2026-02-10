
/* SN_007 - class member */

class SN_007_class {
public:
  SN_007_class(unsigned d) : data(d), offset(2) {}

  void setOffset(int off) {
    offset = off;
  }

  int getOffset() { return offset; }

  unsigned getData() {
    data = data << offset;
    return data;
  }

private:
  int data;
  int offset;
};

unsigned SN_007_function(int flag) {
  unsigned bitData = 0;
  SN_007_class obj(10);

  if(flag > 10) {
    bitData = obj.getData() << obj.getOffset();
    return bitData;
  }
  else {
    obj.setOffset(-2);
    bitData = obj.getData() << obj.getOffset(); //@violation SHIFT_NEGATIVE      
    return bitData; 
  }
}
