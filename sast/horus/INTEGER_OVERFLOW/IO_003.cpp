
/* IO_003 - simple case3 */
unsigned char IO_003_function(unsigned char p1, 
  unsigned char p2, unsigned char p3, int flag) {
  if(flag > 10) {
    if(p1 == 254) {
      p1++; //It's ok.
    }
  }
  else if(flag > 5) {
    if(p2 == 252) {
      p2 -= 10; //It's ok.
    }
  }
  else {
    if(p3 == 252) {
      p3 += 10; //@violation INTEGER_OVERFLOW
    }
  }

  return p1;
}
