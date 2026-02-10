

/* RL_006 - RETURN_LOCAL field pointer return */

struct RL_006_Struct {
  char* ptr;
};

extern void RL_006_function(RL_006_Struct* acc);

char* RL_006_function2(RL_006_Struct* acc) {
  return acc->ptr;
}

char* RL_006_function3() {
  char* z = 0;
  RL_006_Struct obj;

  RL_006_function(&obj);

  z = RL_006_function2(&obj);

  return z; //It's ok.
}

int* RL_006_function4() {
  int arr[100];
  for(int i = 0; i < 100; i++){
    arr[i] = i;
  }
  return arr; //@violation RETURN_LOCAL
}

