
//@checker UNUSED_PARAMETER.MISRA2008

class A
{
	public:
	virtual void withUnusedPara(int * para1,
								int unusedpara) = 0;
	virtual void withoutUnusedPara ( int * para1,
									int & para2) = 0;

};


class B1 : public A
{
	public:
	virtual void withUnusedPara(int * para1,  //@violation UNUSED_PARAMETER.MISRA2008
								int unusedpara)
								{
									*para1 = 1U;
								}
	virtual void withoutUnusedPara ( int * para1, //@violation UNUSED_PARAMETER.MISRA2008
									int & para2) 
								{
									*para1 = 1U;
								}

};


class B2 : public A
{
public:
	virtual void withUnusedPara(int * para1, //@violation UNUSED_PARAMETER.MISRA2008
								int unusedpara) 
								{ 
									*para1 = 1U;
								}




virtual void withoutUnusedPara ( int * para1, //@violation UNUSED_PARAMETER.MISRA2008
								int & para2) 
							{
								para2 = 0;
							}

};


