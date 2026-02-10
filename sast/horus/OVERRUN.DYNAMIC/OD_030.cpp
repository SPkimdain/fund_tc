
/* OD_030 - Abstract factory pattern */
class OD_030_AbstractProductA
{
public:
  virtual void print(int* value) = 0;
};

class OD_030_AbstractProductB
{
public:
  virtual void print(int* value) = 0;
};

class OD_030_ConcreateProductA1 : public OD_030_AbstractProductA
{
public:
  void print(int* value);
};

class OD_030_ConcreateProductA2 : public OD_030_AbstractProductA
{
public:
  void print(int* value);
};

class OD_030_ConcreateProductB1 : public OD_030_AbstractProductB
{
public:
  void print(int* value);
};

class OD_030_ConcreateProductB2 : public OD_030_AbstractProductB
{
public:
  void print(int* value);
};

class OD_030_AbstractFactory
{
public:
  virtual OD_030_AbstractProductA* createProductA() = 0;
  virtual OD_030_AbstractProductB* createProductB() = 0;
};

class OD_030_ConcreateFactory1 : public OD_030_AbstractFactory
{
public:
  virtual OD_030_AbstractProductA* createProductA();
  virtual OD_030_AbstractProductB* createProductB();
};

class OD_030_ConcreateFactory2 : public OD_030_AbstractFactory
{
public:
  virtual OD_030_AbstractProductA* createProductA();
  virtual OD_030_AbstractProductB* createProductB();
};

void OD_030_ConcreateProductA1::print(int* value)
{
  value[3] = 10;
}

void OD_030_ConcreateProductA2::print(int* value)
{
  value[6] = 10;
}

void OD_030_ConcreateProductB1::print(int* value)
{
  value[3] = 40;
}

void OD_030_ConcreateProductB2::print(int* value)
{
  value[6] = 40; 
}

OD_030_AbstractProductA* OD_030_ConcreateFactory1::createProductA()
{
  return new OD_030_ConcreateProductA1;
}

OD_030_AbstractProductB* OD_030_ConcreateFactory1::createProductB()
{
  return new OD_030_ConcreateProductB1;
}

OD_030_AbstractProductA* OD_030_ConcreateFactory2::createProductA()
{
  return new OD_030_ConcreateProductA2;
}

OD_030_AbstractProductB* OD_030_ConcreateFactory2::createProductB()
{
  return new OD_030_ConcreateProductB2;
}

void OD_030_function()
{
  int* p1 = new int[5];
  if(p1 == 0) {
    return;
  }

  int* p2 = new int[10];
  if(p2 == 0) {
    return;
  }

  OD_030_ConcreateFactory1 pFactory1;
  OD_030_ConcreateFactory2 pFactory2;

  OD_030_AbstractProductA* pA1 = pFactory1.createProductA();
  pA1->print(p1); //It's ok.

  OD_030_AbstractProductB* pB1 = pFactory1.createProductB();
  pB1->print(p2); //It's ok.

  OD_030_AbstractProductA* pA2 = pFactory2.createProductA();
  pA2->print(p2); //It's ok.

  OD_030_AbstractProductB* pB2 = pFactory2.createProductB();
  pB2->print(p1); //@violation OVERRUN.DYNAMIC

  delete pA1;
  delete pB1;
  delete pA2;
  delete pB2;

  delete[] p1;
  delete[] p2;
}
