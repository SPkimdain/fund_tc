
/* ND_030 - Abstract factory pattern */
class ND_030_AbstractProductA
{
public:
  virtual void print(int* value) = 0;
};

class ND_030_AbstractProductB
{
public:
  virtual void print(int* value) = 0;
};

class ND_030_ConcreateProductA1 : public ND_030_AbstractProductA
{
public:
  void print(int* value);
};

class ND_030_ConcreateProductA2 : public ND_030_AbstractProductA
{
public:
  void print(int* value);
};

class ND_030_ConcreateProductB1 : public ND_030_AbstractProductB
{
public:
  void print(int* value);
};

class ND_030_ConcreateProductB2 : public ND_030_AbstractProductB
{
public:
  void print(int* value);
};

class ND_030_AbstractFactory
{
public:
  virtual ND_030_AbstractProductA* createProductA() = 0;
  virtual ND_030_AbstractProductB* createProductB() = 0;
};

class ND_030_ConcreateFactory1 : public ND_030_AbstractFactory
{
public:
  virtual ND_030_AbstractProductA* createProductA();
  virtual ND_030_AbstractProductB* createProductB();
};

class ND_030_ConcreateFactory2 : public ND_030_AbstractFactory
{
public:
  virtual ND_030_AbstractProductA* createProductA();
  virtual ND_030_AbstractProductB* createProductB();
};

void ND_030_ConcreateProductA1::print(int* value)
{
  if(value != 0) {
    *value = 10;
  }
}

void ND_030_ConcreateProductA2::print(int* value)
{
  if(value != 0) {
    *value = 20;
  }
}

void ND_030_ConcreateProductB1::print(int* value)
{
    *value = 30;
}

void ND_030_ConcreateProductB2::print(int* value)
{
  *value = 40; // NULL_DEREF
}

ND_030_AbstractProductA* ND_030_ConcreateFactory1::createProductA()
{
  return new ND_030_ConcreateProductA1;
}

ND_030_AbstractProductB* ND_030_ConcreateFactory1::createProductB()
{
  return new ND_030_ConcreateProductB1;
}

ND_030_AbstractProductA* ND_030_ConcreateFactory2::createProductA()
{
  return new ND_030_ConcreateProductA2;
}

ND_030_AbstractProductB* ND_030_ConcreateFactory2::createProductB()
{
  return new ND_030_ConcreateProductB2;
}

void ND_030_function()
{
  int *value = new int();
  *value = 100;
  ND_030_ConcreateFactory1 pFactory1;
  ND_030_ConcreateFactory2 pFactory2;

  ND_030_AbstractProductA* pA1 = pFactory1.createProductA();
  pA1->print(value); //It's ok.

  ND_030_AbstractProductB* pB1 = pFactory1.createProductB();
  pB1->print(value); //It's ok.

  ND_030_AbstractProductA* pA2 = pFactory2.createProductA();
  pA2->print(0); //It's ok.

  ND_030_AbstractProductB* pB2 = pFactory2.createProductB();
  pB2->print(0); //@violation NULL_DEREF

  delete value;
  delete pA1;
  delete pB1;
  delete pA2;
  delete pB2;
}
