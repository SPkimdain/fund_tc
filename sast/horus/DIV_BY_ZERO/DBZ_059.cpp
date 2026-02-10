
/* DBZ_059 - big integer */

void DBZ_059_function() {
  int p = 100;
  
  unsigned long long l1 = 10;
  unsigned long long l2 = 0100000000000000000ULL;
  unsigned long long l3 = l1 / l2; //It's ok.
  
  p = p / 0; //@violation DIV_BY_ZERO
}
