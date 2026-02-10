// @checker DO_NOT_DEFINE_VARIADIC_FUNCTIONS


char *just_declaration(char const*, ...);  // safe

char *concatenate(char const *, ...); // declare here

char *concatenate(char const *s, ...) // @violation DO_NOT_DEFINE_VARIADIC_FUNCTIONS
{
  return 0;
}


char *normal_function(char const *s) // safe
{
  return 0;
}
