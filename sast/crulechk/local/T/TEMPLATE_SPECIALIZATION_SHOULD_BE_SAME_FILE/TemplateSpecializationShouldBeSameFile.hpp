//@checker TEMPLATE_SPECIALIZATION_SHOULD_BE_SAME_FILE
//tmpl.h

template <typename T> void bad_tmpl () {}
template <typename T> void good_tmpl () {}
template <> void good_tmpl<int> () {}
