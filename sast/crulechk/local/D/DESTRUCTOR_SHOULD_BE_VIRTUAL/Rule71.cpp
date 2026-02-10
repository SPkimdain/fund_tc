//@checker DESTRUCTOR_SHOULD_BE_VIRTUAL
#define LEN 80

extern char * strcpy ( char * destination, const char * source );

class GraphicObject {  //@violation DESTRUCTOR_SHOULD_BE_VIRTUAL
 public:
  virtual void display() = 0;    // Pure virtual
  GraphicObject() {
    // ¡¦
  }
  ~GraphicObject() { //@b-violation DESTRUCTOR_SHOULD_BE_VIRTUAL
    // ¡¦
  }
};

class Rectangle : public GraphicObject {	//@violation DESTRUCTOR_SHOULD_BE_VIRTUAL
 public:
  Rectangle() {
    title = new char[LEN+1];
    strcpy(title, "(empty)");
    x1 = 0;
    y1 = 0;
    x2 = 0;
    y2 = 0;
  }
  ~Rectangle() { //@b-violation DESTRUCTOR_SHOULD_BE_VIRTUAL
    delete[] title;
  }
  void display() {
    // ¡¦
  }
 private:
  int x1, y1;
  int x2, y2;
  char * title;
};
