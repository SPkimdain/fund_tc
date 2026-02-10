
class B
{
public:
	B() {}
};

class C 
{ 
public: 
    operator double(); //@violation CONVERSION_OPERATOR_FUNDAMENTAL_TYPE
	operator int() { return a; } //@violation CONVERSION_OPERATOR_FUNDAMENTAL_TYPE
	operator char(); //@violation CONVERSION_OPERATOR_FUNDAMENTAL_TYPE
	operator B(); // Do not check if class type.

private:
	int a;
}; 
