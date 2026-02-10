#include <stdio.h>

/* LR_021 - object copy assign */
class LR_021_Class1 {
public:
  LR_021_Class1() : file(0) {}
  ~LR_021_Class1() {
    if(file != 0) {
      fclose(file);
    }
  }

  LR_021_Class1& move(LR_021_Class1& rhs) {
    if(file != 0) {
      fclose(file);
      file = 0;
    }

    this->file = rhs.file;
    rhs.file = 0; //Move ownership.
    return *this;
  }

  void open(char* fileName) {
    /* Missing check the exist fp. */
    if(file != 0) {
      fclose(file);
      file = 0;
    }
    file = fopen(fileName, "r");
  }

private:
  FILE* file;
};

class LR_021_Class2 {
public:
  LR_021_Class2() : file(0) {}
  ~LR_021_Class2() {
    if(file != 0) {
      fclose(file);
    }
  }

  LR_021_Class2& move(LR_021_Class2& rhs) {
    this->file = rhs.file;
    rhs.file = 0; //Move ownership.
    return *this;
  }

  void open(char* fileName) {
    /* Missing check the exist fp. */
    file = fopen(fileName, "r");
  }

private:
  FILE* file;
};

void LR_021_function(int flag, int flag2) {
  if(flag > 0) {
    LR_021_Class1 obj1;
    obj1.open("filename.txt");

    if(flag2 == 10) {
      LR_021_Class1 obj2;
      obj2.open("1324.txt");

      obj1.move(obj2); //obj1.file is close. obj2.file is moved.
    } //close nothing.
        
  } //calling fclose in obj2.dtor.
  else {
    LR_021_Class2 obj2_1;
    obj2_1.open("abcd.txt");

    if(flag2 == 10) {
      LR_021_Class2 obj2_2;
      obj2_2.open("asdfqwer.txt");
      //obj2_1.file is missing.
      obj2_1.move(obj2_2);
    }
  }
} //@violation LEAK.RESOURCE
