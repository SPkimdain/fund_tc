// @checker DO_NOT_RECURSIVELY_REENTER_DURING_INIT_STATIC

int fact(int i) {
  if (i < 0) {
    // Negative factorials are undefined.
    throw;
  }
  
  static const int cache[] = {	// @violation DO_NOT_RECURSIVELY_REENTER_DURING_INIT_STATIC
    fact(0), fact(1), fact(2), fact(3), fact(4), fact(5),
    fact(6), fact(7), fact(8), fact(9), fact(10), fact(11),
    fact(12), fact(13), fact(14), fact(15), fact(16)
  };

  return i > 0 ? i * fact(i - 1) : 1;
}

int main () {
	
	return 0 ;
}