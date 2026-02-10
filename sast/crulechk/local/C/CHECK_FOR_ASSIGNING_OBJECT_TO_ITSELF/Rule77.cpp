//@checker CHECK_FOR_ASSIGNING_OBJECT_TO_ITSELF

typedef long size_t;
extern size_t strlen ( const char * str );
extern char * strcpy ( char * destination, const char * source );

class Noncompliant {  
 public:
  Noncompliant& operator=(const Noncompliant & sourceName);

 private:
  char *m_name;
};

Noncompliant& Noncompliant::operator=(const Noncompliant & sourceName) { //@violation CHECK_FOR_ASSIGNING_OBJECT_TO_ITSELF
  // return the current memory to the system
  delete[] m_name;
  
  // allocate memory for the copy
  int length = strlen(sourceName.m_name);
  m_name = new char[length + 1];
  
  // copy from the source to this
  strcpy(m_name, sourceName.m_name);
  return(*this);
}

class Compliant {
 public:
  Compliant& operator=(const Compliant & sourceName);

 private:
  char *m_name;
};

Compliant& Compliant::operator=(const Compliant & sourceName) {
  // check whether assigning sourceName to itself
  if (this == &sourceName)
  {
    return (*this);
  }

  // return the current memory to the system
  delete[] m_name;
  
  // allocate memory for the copy
  int length = strlen(sourceName.m_name);
  m_name = new char[length + 1];
  
  // copy from the source to this
  strcpy(m_name, sourceName.m_name);
  return(*this);
}
