extern int info[256];
int f(int aa)
{
  short s;
  unsigned sz;

  s = aa;       //@violation assume id = 65535, s will be -1 due to integer overflow
  if (s > 256) return 0;

  sz = s;       // unexpected sign extension to 4294967295
  return info[sz];  // access out of bound
}

