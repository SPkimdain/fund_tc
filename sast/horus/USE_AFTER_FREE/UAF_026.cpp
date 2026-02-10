
/* UAF_026 - destructor */
class UAF_026_Class{
public:
  UAF_026_Class() {
    ptr = new int(10);
  }
  ~UAF_026_Class() {
    *ptr = 0; 
    //ptr = 0; //It's ok.
  }
  
  void releasePtr() {
    delete ptr;
  }

private:
  int* ptr;
};

void UAF_026_function(bool flag) {
  if(flag == true) {
    UAF_026_Class* obj = new UAF_026_Class;
    obj->releasePtr();

    delete obj; //@violation USE_AFTER_FREE
  }
}
