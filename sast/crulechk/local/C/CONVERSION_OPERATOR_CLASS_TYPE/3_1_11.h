//@checker CONVERSION_OPERATOR_CLASS_TYPE

class B
{
public:
	B() {}
};

class C 
{ 
public: 
    operator double(); 
	operator int() { return a; } 
	operator char(); 
	operator B(); //@violation CONVERSION_OPERATOR_CLASS_TYPE
private:
	int a;
}; 

