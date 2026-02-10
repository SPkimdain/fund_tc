
/* PPTL_007 - local array bind */

struct PPTL_007_Struct {
  int value;
  int* ptr;
};

void PPTL_007_function_init(PPTL_007_Struct* obj, int* arr) {
  obj->ptr = arr;
  obj->value = 10;
}

int* PPTL_007_function2(PPTL_007_Struct* obj, int flag) {
  if(flag > 10) {
    return obj->ptr;
  }
  else {
    return 0;
  }
}

void PPTL_007_function3(int flag, int** out) {
  int* z = 0;
  int arr[100] = { 0, };
  PPTL_007_Struct obj;

  if(flag > 40) {
    PPTL_007_function_init(&obj, arr);

    z = PPTL_007_function2(&obj, 20);
  }

  *out = z;//@violation PARAMETER_POINTER_TO_LOCAL
}

