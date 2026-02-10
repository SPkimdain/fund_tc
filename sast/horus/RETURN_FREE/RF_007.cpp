
/* RF_007 - allocated array bind */

struct RF_007_Struct {
  int value;
  int* ptr;
};

void RF_007_function_init(RF_007_Struct* obj, int* arr) {
  obj->ptr = arr;
  obj->value = 10;
}

int* RF_007_function2(RF_007_Struct* obj, int flag) {
  if(flag > 10) {
    return obj->ptr;
  }
  else {
    return 0;
  }
}

int* RF_007_function3(int flag) {
  int* z = 0;
  int* arr = new int[100];
  RF_007_Struct obj;

  if(flag > 40) {
    RF_007_function_init(&obj, arr);

    z = RF_007_function2(&obj, 20);
  }

  delete[] arr;

  return z;//@violation RETURN_FREE
}

