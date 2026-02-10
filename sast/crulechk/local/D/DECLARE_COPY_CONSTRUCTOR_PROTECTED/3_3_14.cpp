//@checker DECLARE_COPY_CONSTRUCTOR_PROTECTED
class Base { 
public:
  virtual void f() = 0;
  Base& operator=( const Base& );   //@violation DECLARE_COPY_CONSTRUCTOR_PROTECTED
};  
  

class Derived : public Base { 
public:   
  void f() {};
  Derived& operator=( const Derived& ); 
};  


void foo() {    
  Derived obj1;   
  Derived obj2;      

  Base* ptr1 = &obj1;  
  Base* ptr2 = &obj2;   

  *ptr1 = *ptr2;                   
} 
