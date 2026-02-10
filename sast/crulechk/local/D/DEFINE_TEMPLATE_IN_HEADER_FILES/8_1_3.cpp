//@checker DEFINE_TEMPLATE_IN_HEADER_FILES 

#include "8_1_3.hpp"

namespace test
{
	template<typename T>
	T const& myMin( T const& a, T const& b ) //@violation DEFINE_TEMPLATE_IN_HEADER_FILES
	{
		return a < b ? a : b;
	}

	template<typename T>
	T test::TemplTest<T>::getElem() const //@violation DEFINE_TEMPLATE_IN_HEADER_FILES
	{
		return this->elem;
	}
}


int DTIHF_func()
{
  int x = 10, y = 20;
  bool ret = test::myMax<int>(x, y);
  test::TemplTest<int> tt;
  tt.setElem(50);
  x = tt.getElem();
  bool ret2 = test::myMin<int>(x, y);
	return 1;
}
