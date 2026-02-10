//@checker TEMPLATE_SPECIALIZATION_SHOULD_BE_SAME_FILE
//templ.cc

#include "TemplateSpecializationShouldBeSameFile.hpp"

// template <> void good_tmpl<int> () {}
template <> void bad_tmpl<int> () {} //@violation TEMPLATE_SPECIALIZATION_SHOULD_BE_SAME_FILE
