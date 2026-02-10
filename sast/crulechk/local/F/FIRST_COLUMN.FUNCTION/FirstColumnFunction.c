// @checker FIRST_COLUMN.FUNCTION

#define DECL \
  fun() {}

void foo () {
}


void bar ()
{
}


  void zoo () {    // @violation FIRST_COLUMN.FUNCTION
}



DECL
