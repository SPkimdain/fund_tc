//@checker ASSIGN_BASE_CLASS_MEMBERS
// this case has no alarm, base class has no-field
class NBase
{
	
};

class Base : public NBase 
{
public:
	Base& operator=(const Base& rhs)
	{
		bValue = rhs.bValue;

		return *this;
	}

private:
	int bValue;
};