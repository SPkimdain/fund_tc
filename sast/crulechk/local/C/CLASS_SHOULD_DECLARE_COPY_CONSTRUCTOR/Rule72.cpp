//@checker CLASS_SHOULD_DECLARE_COPY_CONSTRUCTOR
typedef long size_t;

extern size_t strlen ( const char * str );
extern char * strcpy ( char * destination, const char * source );

class noncompliant {  //@violation CLASS_SHOULD_DECLARE_COPY_CONSTRUCTOR
 private:
  char *data;
};


class compliant {
 public:
  compliant(const compliant& source) {
    int length = strlen(source.data);
    
    data = new char[length + 1];
    strcpy(data, source.data); 
  }
  
 private:
  char *data;
};


