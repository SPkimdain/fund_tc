//@checker ORDER_EXCEPTIONS_FROM_DERIVED_TO_BASE
// classes used for exception handling
class OEFDTBT_parent {};
class OEFDTBT_child: public OEFDTBT_parent {};

void OEFDTBT_func1()
{
	// ... Using the classes from above
	try { //@violation ORDER_EXCEPTIONS_FROM_DERIVED_TO_BASE
	 // ...
	} catch (OEFDTBT_parent &p) {
	 // ...
	} catch (OEFDTBT_child &c) {
	 // ...
	}

}