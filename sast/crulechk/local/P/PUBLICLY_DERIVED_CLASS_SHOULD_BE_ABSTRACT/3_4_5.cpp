//@checker PUBLICLY_DERIVED_CLASS_SHOULD_BE_ABSTRACT
class Abstract { 
public:
  virtual ~Abstract() = 0;    // ... 
protected:    
  Abstract& operator=( const Abstract& rhs ); 
};  
  
class Concrete1 : public Abstract { 
public:   
  Concrete1& operator=( const Concrete1& rhs );    // ... 
};  
    
class Concrete2 : public Abstract { 
public:    
  Concrete2& operator=( const Concrete2& rhs );    // ...
}; 

class Concrete3 : public Concrete1 {};  //@violation PUBLICLY_DERIVED_CLASS_SHOULD_BE_ABSTRACT
