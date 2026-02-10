//@checker CLASS_SHOULD_DECLARE_ASSIGNMENT_OPERATOR
typedef long size_t;

extern size_t strlen ( const char * str );
extern char * strcpy ( char * destination, const char * source );

class noncompliant {  //@violation CLASS_SHOULD_DECLARE_ASSIGNMENT_OPERATOR
 private:
  char *data;
};


class compliant {
 public:
  compliant& operator=(const compliant& source) {
    delete[] data;
    
    int length = strlen(source.data);
    
    data = new char[length + 1];
    strcpy(data, source.data);

    return *this;
  }
  
 private:
  char *data;
};


