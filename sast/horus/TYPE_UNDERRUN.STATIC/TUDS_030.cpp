
/* TUDS_030 - Abstract factory pattern */
struct TUDS_030_Struct {
  int p1[5];
  int p2[10];
};

class TUDS_030_AbstractProductA
{
public:
  virtual void print(int* value) = 0;
};

class TUDS_030_AbstractProductB
{
public:
  virtual void print(int* value) = 0;
};

class TUDS_030_ConcreateProductA1 : public TUDS_030_AbstractProductA
{
public:
  void print(int* value);
};

class TUDS_030_ConcreateProductA2 : public TUDS_030_AbstractProductA
{
public:
  void print(int* value);
};

class TUDS_030_ConcreateProductB1 : public TUDS_030_AbstractProductB
{
public:
  void print(int* value);
};

class TUDS_030_ConcreateProductB2 : public TUDS_030_AbstractProductB
{
public:
  void print(int* value);
};

class TUDS_030_AbstractFactory
{
public:
  virtual TUDS_030_AbstractProductA* createProductA() = 0;
  virtual TUDS_030_AbstractProductB* createProductB() = 0;
};

class TUDS_030_ConcreateFactory1 : public TUDS_030_AbstractFactory
{
public:
  virtual TUDS_030_AbstractProductA* createProductA();
  virtual TUDS_030_AbstractProductB* createProductB();
};

class TUDS_030_ConcreateFactory2 : public TUDS_030_AbstractFactory
{
public:
  virtual TUDS_030_AbstractProductA* createProductA();
  virtual TUDS_030_AbstractProductB* createProductB();
};

void TUDS_030_ConcreateProductA1::print(int* value)
{
  value[3] = 10;
}

void TUDS_030_ConcreateProductA2::print(int* value)
{
  value[6] = 10;
}

void TUDS_030_ConcreateProductB1::print(int* value)
{
  value[3] = 40;
}

void TUDS_030_ConcreateProductB2::print(int* value)
{
  value[-6] = 40; 
}

TUDS_030_AbstractProductA* TUDS_030_ConcreateFactory1::createProductA()
{
  return new TUDS_030_ConcreateProductA1;
}

TUDS_030_AbstractProductB* TUDS_030_ConcreateFactory1::createProductB()
{
  return new TUDS_030_ConcreateProductB1;
}

TUDS_030_AbstractProductA* TUDS_030_ConcreateFactory2::createProductA()
{
  return new TUDS_030_ConcreateProductA2;
}

TUDS_030_AbstractProductB* TUDS_030_ConcreateFactory2::createProductB()
{
  return new TUDS_030_ConcreateProductB2;
}

void TUDS_030_function()
{
  TUDS_030_Struct sb;
  TUDS_030_ConcreateFactory1 pFactory1;
  TUDS_030_ConcreateFactory2 pFactory2;

  TUDS_030_AbstractProductA* pA1 = pFactory1.createProductA();
  pA1->print(sb.p1); //It's ok.

  TUDS_030_AbstractProductB* pB1 = pFactory1.createProductB();
  pB1->print(sb.p2); //It's ok.

  TUDS_030_AbstractProductA* pA2 = pFactory2.createProductA();
  pA2->print(sb.p2); //It's ok.

  TUDS_030_AbstractProductB* pB2 = pFactory2.createProductB();
  pB2->print(sb.p1); //@violation TYPE_UNDERRUN.STATIC

  delete pA1;
  delete pB1;
  delete pA2;
  delete pB2;
}
