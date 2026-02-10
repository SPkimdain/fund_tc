
/* TUDBC_017 - implicit signed char check. */
struct TUDBC_017_Struct {
  char idx;
  unsigned short buf[19];
};

int TUDBC_017_function(TUDBC_017_Struct* pCur, int flag) {
  if(flag > 10) {
    if(pCur->idx >= 19) {
      return -1;
    }

    pCur->buf[pCur->idx++] = 10; //It's ok.
  }
  else {
    if(pCur->idx <= -3) {
      return -1;
    }

  pCur->buf[pCur->idx++] = 10; //@violation TYPE_UNDERRUN.BAD_COND
  }

  return 0;
}

