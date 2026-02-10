//@checker CLASS_SHOULD_DECLARE_DESTRUCTOR
typedef long size_t;

extern size_t strlen ( const char * str );
extern char * strcpy ( char * destination, const char * source );

class noncompliant {  //@violation CLASS_SHOULD_DECLARE_DESTRUCTOR
 public:
  noncompliant();
  noncompliant(const char*);

 private:
  int m_numberOfSides; // must be >= 3
  char *m_name;
};

noncompliant::noncompliant() {
  m_name = 0;
}

noncompliant::noncompliant(const char* nameString) {
  if ( !nameString )
    return;

  int length = strlen(nameString);
  m_name = new char[length + 1];
  strcpy(m_name, nameString);
}




class compliant {
 public:
  compliant();
  compliant(const char*);
  ~compliant();

 private:
  int m_numberOfSides; // must be >= 3
  char *m_name;
};

compliant::compliant() {
  m_name = 0;
}

compliant::compliant(const char* nameString) {
  if ( !nameString )
    return;

  int length = strlen(nameString);
  m_name = new char[length + 1];
  strcpy(m_name, nameString);
}


compliant::~compliant() {
  delete[] m_name;    // also handles m_name == NULL
}
