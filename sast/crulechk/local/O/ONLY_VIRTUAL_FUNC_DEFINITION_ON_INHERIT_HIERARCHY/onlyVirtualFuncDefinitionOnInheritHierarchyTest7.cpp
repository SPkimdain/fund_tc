//@checker ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY



//TC7////////////////////////
class A
{
public:
virtual void f1() {}
virtual void f2() {}
virtual void f3() = 0;
};


class B1 : public A
{
public:
virtual void f1() = 0;
virtual void f2() {}      //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
virtual void f3() {}
};


class B2 : public A
{
public:
virtual void f1() {}     //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
virtual void f2() {}     //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
virtual void f3() {}     //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
};

class C1 : public B1
{
public:
virtual void f5() {}
virtual void f3() {}    //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
virtual void f1() {}    //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
};


class C2 : public B1, public B2
{
public:
virtual void f1() {}     //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
virtual void f2() = 0;
virtual void f4() {}
};


class C3 : public B2
{
public:
virtual void f5() {}   //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
};



class D1 : public C1, public C2
{
public:
virtual void f4() = 0;
virtual void f2() {}     //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
};


class D2 : public C2, public C3
{
virtual void f3() {}     //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
virtual void f4() {}     //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
};



class E : public D2, public D1
{
virtual void f3() {}     //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
};

//////independent inheritacne hierarchy
class F
{
virtual void f2() {}
virtual void f7() = 0;
};

class G1 : public F
{
virtual void f2() {}    //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
virtual void f7() {}
virtual void f3() {}
};

class G2 : public F
{
virtual void f7() {}    //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
};

class H : public G1, G2
{
virtual void f3() {}   //@violation ONLY_VIRTUAL_FUNC_DEFINITION_ON_INHERIT_HIERARCHY
};


