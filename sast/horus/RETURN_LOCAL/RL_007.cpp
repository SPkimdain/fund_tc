
/* RL_007 - local array bind */

struct RL_007_Struct {
  int value;
  int* ptr;
};

void RL_007_function_init(RL_007_Struct* obj, int* arr) {
  obj->ptr = arr;
  obj->value = 10;
}

int* RL_007_function2(RL_007_Struct* obj, int flag) {
  if(flag > 10) {
    return obj->ptr;
  }
  else {
    return 0;
  }
}

int* RL_007_function3(int flag) {
  int* z = 0;
  int arr[100] = { 0, };
  RL_007_Struct obj;

  if(flag > 40) {
    RL_007_function_init(&obj, arr);

    z = RL_007_function2(&obj, 20);
  }
  
  return z;//@violation RETURN_LOCAL
}

