
/* DBZ_039 - sqrt from opus */
int DBZ_039_function1(int x) {
  int i;
  if(x == 1){
    return 1;
  }
  for(i = 0; i < x; i++) {
    // In the first iteration i == 0, potential divide-by-zero here
    if(x / i < i) { //@violation DIV_BY_ZERO
      break;
    }
  }
  return i;
}
