//@checker BAD_INIT.PURE_VIRTUAL

class BINITPVRT_001_class {
  virtual void wrongPureVirtual() = 1; //@violation BAD_INIT.PURE_VIRTUAL
};

