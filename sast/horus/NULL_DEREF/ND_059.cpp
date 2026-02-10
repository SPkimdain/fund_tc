
/* ND_059 - field deref */
struct ND_059_Struct {
  int value;
  int value2;
  char* value3;
  int* value4;
};

int ND_059_function1(ND_059_Struct* obj) {
  obj->value = 10;
  obj->value2 = 20;
  
  obj->value3 = 0;
  return *(obj->value4);
}

void ND_059_function2() {
  ND_059_Struct obj;
  obj.value3 = 0;
  obj.value4 = 0;

  ND_059_function1(&obj); //@violation NULL_DEREF
}
