//@checker CONST_MEMBER_FUNCTION_SHOULD_NOT_RETURN_NONCONST

class A { 
public: 
  int* foo() const    {     //@violation CONST_MEMBER_FUNCTION_SHOULD_NOT_RETURN_NONCONST  
    return m_pa;   
  }  
  int const * bar() const    {      //@violation CONST_MEMBER_FUNCTION_SHOULD_NOT_RETURN_NONCONST
    return m_pa;    
  }  
private:  
  int* m_pa; 
};  



void bar() {   
  const A a;  
  int* pa = a.foo();  
  *pa = 10;          // modifies private data in a!  
}
