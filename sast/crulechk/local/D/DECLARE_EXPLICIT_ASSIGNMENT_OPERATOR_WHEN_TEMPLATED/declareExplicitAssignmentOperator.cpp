//@checker DECLARE_EXPLICIT_ASSIGNMENT_OPERATOR_WHEN_TEMPLATED

//TC 1 
class A
{
public: 
	/*
	A& operator=(A const &rhs)  
	{
		return *this;
	}
	*/

	template <typename T>   
	T& operator= (T const &rhs)  //@violation DECLARE_EXPLICIT_ASSIGNMENT_OPERATOR_WHEN_TEMPLATED
	{
		return *this; 
	}  
};


//TC 2
class B
{
public:
	B& operator=(B const &rhs)  
	{
		return *this;
	}

	template <typename T>   
	T& operator=(T const &rhs)   
	{
		return *this;
	}
};


//TC 3
class C
{
public:
	template <typename T>
	T& operator=(T const &rhs)   
	{
		return *this;
	}

	C& operator=(C const &rhs)  
	{
		return *this;
	}
};


//TC 4
class D
{
public:
	D& operator=(D const &rhs)  
	{
		return *this;
	}
};


//TC 5
class E
{
public:
	E() {}   //Default Constructor

	template <typename T>
	T& operator=(T const &rhs)   //@violation DECLARE_EXPLICIT_ASSIGNMENT_OPERATOR_WHEN_TEMPLATED
	{
		return *this;
	}
};


//TC 6
class F
{
public:
	F(const F &copy) {}   //Copy Constructor
	
	template <typename T>
	T& operator=(T const &rhs)   //@violation DECLARE_EXPLICIT_ASSIGNMENT_OPERATOR_WHEN_TEMPLATED
	{
		return *this;
	}
};