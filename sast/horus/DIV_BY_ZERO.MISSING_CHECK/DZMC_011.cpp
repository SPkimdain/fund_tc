

/* DZMC_011 - field from opus */
struct DZMC_011_Struct {
  int v;
};


int DZMC_011_function1(int z, struct DZMC_011_Struct& n){
  if(z > 0)
    return z / (n.v);
  else return 1;
}

int DZMC_011_function2(struct DZMC_011_Struct& n){
  int x = 0, y = 1;
  int z = 0;
  
  if(n.v != 0) {
    y--;
  }
  
  z = DZMC_011_function1(y - 2, n); //It's ok.
  
  z = z + 10;
  
  z = z / n.v; //@violation DIV_BY_ZERO.MISSING_CHECK
  return 0;
}
