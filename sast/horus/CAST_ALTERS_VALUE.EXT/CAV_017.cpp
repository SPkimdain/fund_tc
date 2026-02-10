/* cpp + smaller type */

class CAV_017_Class {  
public:
  void CAV_017_function();
private:
  short value;
  unsigned short value2;
};

void CAV_017_Class::CAV_017_function() {
  const int x = 30000;
  const int y = 5000;
 
  value2 = x + 10000; //It's ok.
  value = x + y; //@violation CAST_ALTERS_VALUE.EXT
}


