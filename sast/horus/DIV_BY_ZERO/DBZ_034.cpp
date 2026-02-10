

/* DBZ_034 - field from opus */
struct DBZ_034_Struct {
  int v;
};


int DBZ_034_function1(int z, struct DBZ_034_Struct n){
  if(z > 0)
    return z / (n.v); // DIV_BY_ZERO
  else return 1;
}

int DBZ_034_function2(){
  int x = 0, y = 1;
  int z = 0;
  struct DBZ_034_Struct n;
  n.v = y;
  z = DBZ_034_function1(y - 2, n); //It's ok.
  n.v = x;
  z = z + 10;
  z = DBZ_034_function1(z, n); //@violation DIV_BY_ZERO
  return 0;
}
