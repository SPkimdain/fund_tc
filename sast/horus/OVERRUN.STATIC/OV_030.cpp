
/* OV_030 - Abstract factory pattern */
class OV_030_AbstractProductA
{
public:
  virtual void print(int* value) = 0;
};

class OV_030_AbstractProductB
{
public:
  virtual void print(int* value) = 0;
};

class OV_030_ConcreateProductA1 : public OV_030_AbstractProductA
{
public:
  void print(int* value);
};

class OV_030_ConcreateProductA2 : public OV_030_AbstractProductA
{
public:
  void print(int* value);
};

class OV_030_ConcreateProductB1 : public OV_030_AbstractProductB
{
public:
  void print(int* value);
};

class OV_030_ConcreateProductB2 : public OV_030_AbstractProductB
{
public:
  void print(int* value);
};

class OV_030_AbstractFactory
{
public:
  virtual OV_030_AbstractProductA* createProductA() = 0;
  virtual OV_030_AbstractProductB* createProductB() = 0;
};

class OV_030_ConcreateFactory1 : public OV_030_AbstractFactory
{
public:
  virtual OV_030_AbstractProductA* createProductA();
  virtual OV_030_AbstractProductB* createProductB();
};

class OV_030_ConcreateFactory2 : public OV_030_AbstractFactory
{
public:
  virtual OV_030_AbstractProductA* createProductA();
  virtual OV_030_AbstractProductB* createProductB();
};

void OV_030_ConcreateProductA1::print(int* value)
{
  value[3] = 10;
}

void OV_030_ConcreateProductA2::print(int* value)
{
  value[6] = 10;
}

void OV_030_ConcreateProductB1::print(int* value)
{
  value[3] = 40;
}

void OV_030_ConcreateProductB2::print(int* value)
{
  value[6] = 40; 
}

OV_030_AbstractProductA* OV_030_ConcreateFactory1::createProductA()
{
  return new OV_030_ConcreateProductA1;
}

OV_030_AbstractProductB* OV_030_ConcreateFactory1::createProductB()
{
  return new OV_030_ConcreateProductB1;
}

OV_030_AbstractProductA* OV_030_ConcreateFactory2::createProductA()
{
  return new OV_030_ConcreateProductA2;
}

OV_030_AbstractProductB* OV_030_ConcreateFactory2::createProductB()
{
  return new OV_030_ConcreateProductB2;
}

void OV_030_function()
{
  int p1[5] = { 0, };
  int p2[10] = { 0, };
  OV_030_ConcreateFactory1 pFactory1;
  OV_030_ConcreateFactory2 pFactory2;

  OV_030_AbstractProductA* pA1 = pFactory1.createProductA();
  pA1->print(p1); //It's ok.

  OV_030_AbstractProductB* pB1 = pFactory1.createProductB();
  pB1->print(p2); //It's ok.

  OV_030_AbstractProductA* pA2 = pFactory2.createProductA();
  pA2->print(p2); //It's ok.

  OV_030_AbstractProductB* pB2 = pFactory2.createProductB();	// OVERRUN.STATIC
  pB2->print(p1); //@violation OVERRUN.STATIC

  delete pA1;
  delete pB1;
  delete pA2;
  delete pB2;
}
