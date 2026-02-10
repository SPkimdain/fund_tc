
/* SN_008 - class member2 */
class SN_008_class {
public:
  SN_008_class() : offset(2) {}

  void setOffset(int off) {
    if(off < 0) { //wrong condition
      offset = off;
    }
    else {
      offset = 1;
    }
  }

  int getOffset() { return offset; }

private:
  int offset;
};

unsigned SN_008_function(int flag, unsigned bitData, int offval) {
  SN_008_class obj;

  if(flag > 10) {
    bitData = bitData << obj.getOffset();
    return bitData;
  }
  else {
    obj.setOffset(offval);
    bitData = bitData << obj.getOffset(); //@violation SHIFT_NEGATIVE  
    return bitData; 
  }
}

