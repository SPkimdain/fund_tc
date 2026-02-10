//@checker TEMPLATE_SPECIALIZATION_SHOULD_BE_SAME_FILE
//f.cc
#include "TemplateSpecializationShouldBeSameFile.hpp"

void f ()
{
  bad_tmpl<int> ();
  good_tmpl<int> ();

}
