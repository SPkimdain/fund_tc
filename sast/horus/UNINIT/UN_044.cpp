#pragma warning(disable : 4700)

/* UN_044 - uninit_04_01 from opus */
struct UN_044_Struct1 {
  int i;
  char c;
  long l;
};

struct UN_044_Struct2 {
  UN_044_Struct1 st_sub;
};

int UN_044_function()
{
  long x;
  UN_044_Struct2 st;
  st.st_sub.i = 0;
  st.st_sub.c = 1;
  x = st.st_sub.l;   //@violation UNINIT
  
  return 0;
}
