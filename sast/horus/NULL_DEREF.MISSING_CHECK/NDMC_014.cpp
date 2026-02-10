
/* NDMC_014 - Wrong message */
struct NDMC_014_Struct {
  int x;
  NDMC_014_Struct* next;
};

class NDMC_014_Struct2 {
public:
  NDMC_014_Struct2() : value(0), ptr(0) {}

  void setValue(int v) {
    value = v;
  }

  void NDMC_014_function2(int size);

private:
  int value;
  NDMC_014_Struct* ptr;
};

extern NDMC_014_Struct* NDMC_014_Create();

void NDMC_014_Struct2::NDMC_014_function2(int size) {
  if(ptr == 0) {
    NDMC_014_Struct* obj = NDMC_014_Create();
    for(int i = 0; i < size; i++) {
      obj->next = ptr;
      ptr = obj;
    }
  }

  NDMC_014_Struct* assoc = 0;
    
  assoc = ptr;  
  
  int yy = assoc->x; //@violation NULL_DEREF.MISSING_CHECK
}


