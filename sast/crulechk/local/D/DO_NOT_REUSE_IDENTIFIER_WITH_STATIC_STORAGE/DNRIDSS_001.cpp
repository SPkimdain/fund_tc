//@checker DO_NOT_REUSE_IDENTIFIER_WITH_STATIC_STORAGE

namespace DNRIDSS_001 {
  static int globalVar5 = 0;
}

namespace DNRIDSS_001_2 {
  void DNRIDSS_001_function() {
    short globalVar5; //@violation DO_NOT_REUSE_IDENTIFIER_WITH_STATIC_STORAGE
  }
}
