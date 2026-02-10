
/* TUDBC_013 - Field access */
class TUDBC_013_Class {
public:
  struct TUDBC_013_Struct {
    int value;
    int value2;
  };

  void TUDBC_013_function(int index) {    
    if(index <= 5 && index >= 0) {
      obj[index - 1].value = 20; //@violation TYPE_UNDERRUN.BAD_COND
    }
  }

private:
  TUDBC_013_Struct obj[5];
};

