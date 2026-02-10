
/* UDS_048 - member call */
class UDS_048_Class {
public:
  int valueReturn(int flag) { 
    if(flag > 10) {
      return -1;
    }
    return 10;
  }
};

void UDS_048_function(int flag) {
  UDS_048_Class obj;
  UDS_048_Class* objPtr = &obj;
  int p[10] = { 0, };
  p[objPtr->valueReturn(15)] = 10; //@violation UNDERRUN.STATIC
}
