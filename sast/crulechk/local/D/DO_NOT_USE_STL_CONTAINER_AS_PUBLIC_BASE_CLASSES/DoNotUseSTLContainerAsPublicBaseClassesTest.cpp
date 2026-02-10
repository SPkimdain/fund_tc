//@checker DO_NOT_USE_STL_CONTAINER_AS_PUBLIC_BASE_CLASSES

#include <vector>

class MyVector : public std::vector<int> {};  //@violation DO_NOT_USE_STL_CONTAINER_AS_PUBLIC_BASE_CLASSES

void doSomething() {
  MyVector* pHeapVec = new MyVector;
  std::vector<int>* pBaseVec = pHeapVec;
  delete pBaseVec;
}


// void foo ()
// {
//   std::vector<int> v;
// }
