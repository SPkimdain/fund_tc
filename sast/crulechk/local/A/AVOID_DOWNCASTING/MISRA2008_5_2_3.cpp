//@checker AVOID_DOWNCASTING

class Colour{};
void setColour(Colour const &);



class D
{
	virtual bool hasColour() const = 0;
	virtual Colour getColour() const = 0;
};



class B : public D
{
public:
	virtual bool hasColour() const
	{
		return true;
	}

	virtual Colour getColour() const
	{
		return m_colour;
	}
private:
	Colour m_colour;
};

class C : public D
{
public:
	virtual bool hasColour() const
	{
		return true;
	}

	virtual Colour getColour() const
	{
		return m_colour;
	}
private:
	Colour m_colour;
};



class A : public B, public C
{
public:
	virtual bool hasColour() const
	{
		return true;
	}

	virtual Colour getColour() const
	{
		return m_colour;
	}
private:
	Colour m_colour;
};




class Obj : public A
{
public:
	virtual bool hasColour() const
	{
		return true;
	}

	virtual Colour getColour() const
	{
		return m_colour;
	}
private:
	Colour m_colour;
};


class ObjWithColour : public Obj
{
public:
	virtual bool hasColour() const
	{
		return true;
	}

	virtual Colour getColour() const
	{
		return m_colour;
	}
private:
	Colour m_colour;
};


void badPrintObject(C const &obj)
{                  
	ObjWithColour const *pObj = dynamic_cast<ObjWithColour const*>(&obj);  //@violation AVOID_DOWNCASTING

	if (0 != pObj)
	{
		setColour(pObj->getColour());
	}
}

void goodPrintObject(Obj const &obj)
{
	if (obj.hasColour())
	{
		setColour(obj.getColour());
	}
}