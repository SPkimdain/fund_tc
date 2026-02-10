//@checker PUBLIC_STATIC_FIELD_WITHOUT_CONST

class PSFWC_001_Class {
public:
  static char* appPropertiesConfigFile; 
  
  static const char* check;
  
  static int check2; 
    
private:
  static int check3;
  
  int x;
};



char* PSFWC_001_Class::appPropertiesConfigFile = "test"; //@violation PUBLIC_STATIC_FIELD_WITHOUT_CONST

const char* PSFWC_001_Class::check = "13234";  //It's ok.

int PSFWC_001_Class::check2 = 10; //@violation PUBLIC_STATIC_FIELD_WITHOUT_CONST

int PSFWC_001_Class::check3 = 50;  //It's ok.
