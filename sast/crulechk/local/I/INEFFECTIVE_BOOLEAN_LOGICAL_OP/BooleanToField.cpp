// @checker INEFFECTIVE_BOOLEAN_LOGICAL_OP

typedef bool CTBOOLEAN;

bool testbool();


class C1
{
    public:
    CTBOOLEAN m_initUpdate;
};

CTBOOLEAN testrun()
{
    bool test = false;
    CTBOOLEAN sec = false;
    C1 temp;
    return  (!temp.m_initUpdate) ;
}