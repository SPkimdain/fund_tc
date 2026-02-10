
/* SEB_008 - class member2 */
class SEB_008_class {
public:
  SEB_008_class() : offset(2) {}

  void setOffset(int off) {
    if(off > 16) { //wrong condition
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

unsigned SEB_008_function(int flag, unsigned short bitData, int offval) {
  SEB_008_class obj;

  if(flag > 10) {
    bitData = bitData << obj.getOffset();
    return bitData;
  }
  else {
    obj.setOffset(offval);
    bitData = bitData << obj.getOffset(); //@violation SHIFT_EXCEEDS_BIT_WIDTH  
    return bitData;
  }
}

