
/* TOS_064 - Check constraint range. */

class TOS_064_Class {
public:
  TOS_064_Class() : arr(), count(0) {}

  bool remove(unsigned idx) {
    if(idx >= count) {
      return false;
    }

    arr[count] = 0;

    count--;

    return true;
  }

  void removeAll() {
    while(count) {
      remove(count - 1U);
    }
  }

  int get(unsigned idx) {
    return arr[idx];
  }

private:
  int arr[64];
  unsigned count;
};

class TOS_064_Class2 {
  TOS_064_Class2() : obj() {}

  int listen() {
    obj.removeAll(); //It's ok.

    return 0;
  }

  int get() {
    return obj.get(65); //@violation TYPE_OVERRUN.STATIC
    return 0;
  }
private:
  TOS_064_Class obj;
};
