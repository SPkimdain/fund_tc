

/* DBZ_037 - int33-c from opus */
signed long DBZ_037_function(int x){
  signed long sl1 = 1;
  signed long sl2 = 1;
  signed long result;

  if(x <= 10) {
    sl2 = 10;
    sl1 = 20;
  }
  else {
    sl1 = 10;
    sl2 = 20;
  }

  if(sl2 > sl1) {
    x = sl2 - sl1;
  }
  else {
    x = sl1 - sl2;
  }

  sl2 = 10;

  result = sl2 / (sl2 - sl1); //@violation DIV_BY_ZERO

  return result;
}
