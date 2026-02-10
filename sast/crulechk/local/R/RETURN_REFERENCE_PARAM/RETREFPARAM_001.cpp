//@checker RETURN_REFERENCE_PARAM

class RETREFPARAM_001_Class {};

RETREFPARAM_001_Class& RETREFPARAM_001_function(int flag, RETREFPARAM_001_Class& obj) {
  if(flag > 10) {
    return obj; //@violation RETURN_REFERENCE_PARAM
  }
  else {
    RETREFPARAM_001_Class* heapObj = new RETREFPARAM_001_Class();

    return *heapObj;
  }
}
