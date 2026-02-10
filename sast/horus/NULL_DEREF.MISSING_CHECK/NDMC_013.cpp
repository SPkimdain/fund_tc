
/* NDMC_013 - Wrong message */
struct NDMC_013_Struct {
  int x;
  NDMC_013_Struct* next;
};

class NDMC_013_Struct2 {
public:
  NDMC_013_Struct2() : value(0), ptr(0) {}

  void setValue(int v) {
    value = v;
  }

  void NDMC_013_function2(int size);

private:
  int value;
  NDMC_013_Struct* ptr;
};

extern NDMC_013_Struct* NDMC_013_Create();

void NDMC_013_Struct2::NDMC_013_function2(int size) {
  if(ptr == 0) {
    NDMC_013_Struct* obj = NDMC_013_Create();
    for(int i = 0; i < size; i++) {
      obj->next = ptr;
      ptr = obj;
    }
  }

  NDMC_013_Struct* assoc = ptr;  
  
  int yy = assoc->x; //@violation NULL_DEREF.MISSING_CHECK
}


