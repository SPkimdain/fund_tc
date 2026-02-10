//@checker EXPLICIT_VIRTUAL_KEYWORD
class A { 
public:    
  virtual void f(); 
  virtual void operator+( A const& );
  virtual ~A(); 
};  

class B1 : public A  { 
public:   
  virtual void f();                      
  virtual void operator+( A const& );    
  virtual ~B1();                         
};

class B2 : public A {
public:   
  void f();                      //@violation EXPLICIT_VIRTUAL_KEYWORD   
  void operator+( A const& );    //@violation EXPLICIT_VIRTUAL_KEYWORD  
  ~B2();                         //@violation EXPLICIT_VIRTUAL_KEYWORD 
};
