
/* UN_030 - Abstract factory pattern */
class UN_030_AbstractProductA
{
public:
  virtual void print(int* value) = 0;
};

class UN_030_AbstractProductB
{
public:
  virtual void print(int* value) = 0;
};

class UN_030_ConcreateProductA1 : public UN_030_AbstractProductA
{
public:
  void print(int* value);
};

class UN_030_ConcreateProductA2 : public UN_030_AbstractProductA
{
public:
  void print(int* value);
};

class UN_030_ConcreateProductB1 : public UN_030_AbstractProductB
{
public:
  void print(int* value);
};

class UN_030_ConcreateProductB2 : public UN_030_AbstractProductB
{
public:
  void print(int* value);
};

class UN_030_AbstractFactory
{
public:
  virtual UN_030_AbstractProductA* createProductA() = 0;
  virtual UN_030_AbstractProductB* createProductB() = 0;
};

class UN_030_ConcreateFactory1 : public UN_030_AbstractFactory
{
public:
  virtual UN_030_AbstractProductA* createProductA();
  virtual UN_030_AbstractProductB* createProductB();
};

class UN_030_ConcreateFactory2 : public UN_030_AbstractFactory
{
public:
  virtual UN_030_AbstractProductA* createProductA();
  virtual UN_030_AbstractProductB* createProductB();
};

void UN_030_ConcreateProductA1::print(int* value)
{
  *value = 10;
}

void UN_030_ConcreateProductA2::print(int* value)
{
  int ret = *value;
}

void UN_030_ConcreateProductB1::print(int* value)
{
  *value = 10;  
}

void UN_030_ConcreateProductB2::print(int* value)
{
  int ret = *value; // UNINIT
}

UN_030_AbstractProductA* UN_030_ConcreateFactory1::createProductA()
{
  return new UN_030_ConcreateProductA1;
}

UN_030_AbstractProductB* UN_030_ConcreateFactory1::createProductB()
{
  return new UN_030_ConcreateProductB1;
}

UN_030_AbstractProductA* UN_030_ConcreateFactory2::createProductA()
{
  return new UN_030_ConcreateProductA2;
}

UN_030_AbstractProductB* UN_030_ConcreateFactory2::createProductB()
{
  return new UN_030_ConcreateProductB2;
}

void UN_030_function()
{
  int p1;
  int p2;
  int p3;
  UN_030_ConcreateFactory1 pFactory1;
  UN_030_ConcreateFactory2 pFactory2;

  UN_030_AbstractProductA* pA1 = pFactory1.createProductA();
  pA1->print(&p1); //It's ok. p1 = 10,

  UN_030_AbstractProductB* pB1 = pFactory1.createProductB();
  pB1->print(&p2); //It's ok. p2 = 10,

  UN_030_AbstractProductA* pA2 = pFactory2.createProductA();
  pA2->print(&p1); //It's ok.

  UN_030_AbstractProductB* pB2 = pFactory2.createProductB();
  pB2->print(&p3);	//@violation UNINIT

  delete pA1;
  delete pB1;
  delete pA2;
  delete pB2;
}
