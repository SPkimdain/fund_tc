//@checker DO_NOT_DERIVE_FROM_VIRTUAL_BASE

class B{};
class D : public virtual B {} ; //@violation DO_NOT_DERIVE_FROM_VIRTUAL_BASE
 

