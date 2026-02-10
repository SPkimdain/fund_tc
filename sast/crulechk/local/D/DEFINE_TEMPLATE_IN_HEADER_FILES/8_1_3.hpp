//@checker DEFINE_TEMPLATE_IN_HEADER_FILES 

namespace test
{
	template<typename T>
	T const& myMax( T const& a, T const& b )
	{
		return a > b ? a : b;
	}

	template<typename T>
	class TemplTest
	{
	public:
		TemplTest() {}

		void setElem( T const& _elem )
		{
			elem = _elem;
		}

		T getElem() const;

	private:
		T elem;
	};

}
