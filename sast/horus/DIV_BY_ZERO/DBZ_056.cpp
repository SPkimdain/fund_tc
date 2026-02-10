
/* DBZ_056 global variable */
int DBZ_056_Var;

void DBZ_056_function1(int value) {
  DBZ_056_Var = value;
}
void DBZ_056_function2() {
  int* ptr = 0;
  int value = 5;
  DBZ_056_function1(value);
  
  int ret = 10000 / (DBZ_056_Var - value); //@violation DIV_BY_ZERO

}

