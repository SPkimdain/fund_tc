#pragma warning(disable : 4700)

/* UN_040 - uninit_03_01 from opus */
struct UN_040_Struct {
  int i;
  char c;
  long l;
};

int UN_040_function() {
  long x;
  UN_040_Struct st;
  st.i = 0;
  st.c = 1;
  x = st.l;   //@violation UNINIT
  return x; //Ignore.
}
