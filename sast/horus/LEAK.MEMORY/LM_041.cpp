#include <stdexcept>
#include <iostream>

/* LM_041 - exception / deep throw */
using namespace std;

class LM_041_Exception : public exception {
public:
  void print() {
    cout << "Error code : 1";
  }
};


void LM_041_function1(bool isThrow) {
  if(isThrow == true) {
    throw LM_041_Exception();
  }
}

void LM_041_function2(int data) {
  data++;

  if(data > 10) {
    LM_041_function1(true);
  }
  else {
    LM_041_function1(false);
  }
}

int LM_041_function3(int data) {
  LM_041_function2(data);
  return 0;
}

int LM_041_function4() {
  int* buf = 0;
  int* buf2 = 0;
  
  try {
    buf = new int[10];
    
    LM_041_function3(0); //It's ok.
    
    delete[] buf;
    buf = 0;

    buf2 = new int[20];

    LM_041_function3(20); //Throw.

    delete[] buf2;
    buf2 = 0;
  }
  catch(exception& e) {
    cout << e.what();
    return 1;
  } //@violation LEAK.MEMORY

  return 0;
}

