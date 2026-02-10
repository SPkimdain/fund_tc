//@checker INTEGER_PRECISION
#define CHAR_BIT 8

unsigned int pow2(unsigned int exp) {
  if (exp >= sizeof(unsigned int) * CHAR_BIT) { //@violation INTEGER_PRECISION
    /* Handle error */
  }
  return 1 << exp;
}