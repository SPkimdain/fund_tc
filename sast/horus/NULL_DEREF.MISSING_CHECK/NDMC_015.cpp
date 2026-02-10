
/* NDMC_015 - three null dereference4 from opus */
void NDMC_015_function(int*** ppp) {
  int x = 0;
  if(ppp == 0) return;
  if(*ppp == 0) return;
  if(**ppp == 0) {
    x++;
  }
  (**ppp)[0] = 'a'; //@violation NULL_DEREF.MISSING_CHECK
}
