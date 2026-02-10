
/* LM_053 - destructor2 */
class LM_053_Class {
public:
  LM_053_Class(unsigned len) {
    length = len;
    data = new char[len]();
  }
  
  ~LM_053_Class() {
    delete[] data;
  }
  
  char* get() { return data; }
  
private:
  unsigned length;
  char* data;
};

class LM_053_Class2 {
public:
  LM_053_Class2() {
    int v = 0;
    LM_053_Class str(10);
    str.get();    
    v++;
    
    LM_053_function();
    
  } //It's ok.
  
  void LM_053_function() {
    int x = 0;
    x++;
  }

private:
  
};

void LM_053_function() {
  int* ptr = new int(10);
} //@violation LEAK.MEMORY
