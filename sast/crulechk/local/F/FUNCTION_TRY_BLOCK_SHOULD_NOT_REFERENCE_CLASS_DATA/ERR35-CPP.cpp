//@checker FUNCTION_TRY_BLOCK_SHOULD_NOT_REFERENCE_CLASS_DATA
class NoncompliantC {
private:
  int x;
public:
  NoncompliantC(int init_x) try : x(init_x) {
    // ...
  } catch (...) {
    if (0 == x) { //@violation FUNCTION_TRY_BLOCK_SHOULD_NOT_REFERENCE_CLASS_DATA
      // ...
    }
  }
};


class CompliantC {
private:
  int x;
public:
  CompliantC(int init_x) try : x(init_x) {
    // ...
  } catch (...) {
    if (0 == init_x) {
      // ...
    }
  }
};

