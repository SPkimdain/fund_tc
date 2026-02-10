//@checker DECLARE_EXPLICIT

class DCLEXPLT_001_Class 
{ 
public: 
    DCLEXPLT_001_Class( const DCLEXPLT_001_Class& ); // ok copy constructor 
    DCLEXPLT_001_Class(); // ok default constructor 
    DCLEXPLT_001_Class( int, int, int i=0 ); // ok more than one non-default argument
    
    explicit DCLEXPLT_001_Class( int ); // prefer 
	DCLEXPLT_001_Class( double ); //@violation DECLARE_EXPLICIT
    DCLEXPLT_001_Class( float f, //@violation DECLARE_EXPLICIT
	   int i=0 ); 
    DCLEXPLT_001_Class( int i=0, float f=0.0 ); //@violation DECLARE_EXPLICIT
	// avoid, default constructor, but also a conversion constructor 
	DCLEXPLT_001_Class( int i=0, float f=0.0, int k=1 ); //@violation DECLARE_EXPLICIT
}; 
