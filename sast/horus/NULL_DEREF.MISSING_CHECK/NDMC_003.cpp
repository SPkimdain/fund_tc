

/* NDMC_003 - assume value */

typedef int VALUE;

extern char* NDMC_003_function1(int* str);

extern char* NDMC_003_function3(char s);

extern void NDMC_003_function4(int *i);
extern void NDMC_003_function5(int *i);

extern VALUE NDMC_003_function6();

int NDMC_003_function2(char* val) {
	const char* s = val;
	if (!val){
		return 0;
	}
	while (NDMC_003_function3(*val)) val++;  
  return 1;
}

void NDMC_003_function(int a, VALUE val) {
	char* tmp = "temp";	
  char* s;
  if (a){
	  s = tmp;
  }
  else{	  
	  s = NDMC_003_function1(&val);
  }
  
  int len = 0;
  if(s) {
    len++;
  }

  val = NDMC_003_function6();
  
  int ret = NDMC_003_function2(s); //it's ok

  char c = *s; //@violation NULL_DEREF.MISSING_CHECK

}


