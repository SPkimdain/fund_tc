
/* TOBC_013 - Field access */
class TOBC_013_Class {
public:
  struct TOBC_013_Struct {
    int value;
    int value2;
  };

  void TOBC_013_function(unsigned index) {    
    if(index < 10) {
      obj[index].value = 20; //@violation TYPE_OVERRUN.BAD_COND
    }
  }

private:
  TOBC_013_Struct obj[5];
};

