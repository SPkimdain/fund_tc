
/* TUDS_045 - complex path from opus */
class TUDS_045_Class {
public:
  void TUDS_045_function(int a) {
    int* ptr = p;
    if(a > 10){
      ptr = p - 15;
    }

    if(a < 10) {
      *ptr = 10; //It's ok.
    }

    if(a > 0) {
      *ptr = 5; //@violation TYPE_UNDERRUN.STATIC
    }
  }

private:
  int p[10];
};
