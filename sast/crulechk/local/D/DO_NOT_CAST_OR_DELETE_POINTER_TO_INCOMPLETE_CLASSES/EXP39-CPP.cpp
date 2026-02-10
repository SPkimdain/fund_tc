// @checker DO_NOT_CAST_OR_DELETE_POINTER_TO_INCOMPLETE_CLASSES


class NoncompliantBody; // incomplete class declaration

class NoncompliantHandle {
  public:
    NoncompliantHandle();
    ~NoncompliantHandle() { delete impl_; } // @violation DO_NOT_CAST_OR_DELETE_POINTER_TO_INCOMPLETE_CLASSES

    // ...
  private:
    NoncompliantBody *impl_;
};



class CompliantBody; // incomplete class declaration

class CompliantHandle {
  public:
    CompliantHandle();
    ~CompliantHandle();
    // ...
  private:
    CompliantBody *impl_;
};


class CompliantBody {
};


CompliantHandle::~CompliantHandle() { delete impl_; } // correct.



class B {
    // ...
};

B *getMeSomeSortOfB();
// ...
class D; // incomplete declaration
// ...

void foo (){
    B *bp = getMeSomeSortOfB();
    D *dp = (D *)bp; // @violation DO_NOT_CAST_OR_DELETE_POINTER_TO_INCOMPLETE_CLASSES
    dp = reinterpret_cast<D *>(bp); // @violation DO_NOT_CAST_OR_DELETE_POINTER_TO_INCOMPLETE_CLASSES
}




// class D : public SomeClass, public B {
//     // ...
// };

// B *getMeSomeSortOfB() { return new D; }
