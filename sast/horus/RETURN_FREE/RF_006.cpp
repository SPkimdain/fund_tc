

/* RF_006 - Field pointer return */

struct RF_006_Struct {
  char* ptr;
};

extern void RF_006_function(RF_006_Struct* acc);

char* RF_006_function2(RF_006_Struct* acc) {  
  return acc->ptr;
}

char* RF_006_function3() {
  char* z = 0;
  RF_006_Struct obj;

  RF_006_function(&obj);

  z = RF_006_function2(&obj);

  delete obj.ptr;

  return z; //@violation RETURN_FREE
}
