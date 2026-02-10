
/* UDS_030 - Abstract factory pattern */
class UDS_030_AbstractProductA
{
public:
  virtual void print(int* value) = 0;
};

class UDS_030_AbstractProductB
{
public:
  virtual void print(int* value) = 0;
};

class UDS_030_ConcreateProductA1 : public UDS_030_AbstractProductA
{
public:
  void print(int* value);
};

class UDS_030_ConcreateProductA2 : public UDS_030_AbstractProductA
{
public:
  void print(int* value);
};

class UDS_030_ConcreateProductB1 : public UDS_030_AbstractProductB
{
public:
  void print(int* value);
};

class UDS_030_ConcreateProductB2 : public UDS_030_AbstractProductB
{
public:
  void print(int* value);
};

class UDS_030_AbstractFactory
{
public:
  virtual UDS_030_AbstractProductA* createProductA() = 0;
  virtual UDS_030_AbstractProductB* createProductB() = 0;
};

class UDS_030_ConcreateFactory1 : public UDS_030_AbstractFactory
{
public:
  virtual UDS_030_AbstractProductA* createProductA();
  virtual UDS_030_AbstractProductB* createProductB();
};

class UDS_030_ConcreateFactory2 : public UDS_030_AbstractFactory
{
public:
  virtual UDS_030_AbstractProductA* createProductA();
  virtual UDS_030_AbstractProductB* createProductB();
};

void UDS_030_ConcreateProductA1::print(int* value)
{
  value[3] = 10;
}

void UDS_030_ConcreateProductA2::print(int* value)
{
  value[6] = 10;
}

void UDS_030_ConcreateProductB1::print(int* value)
{
  value[3] = 40;
}

void UDS_030_ConcreateProductB2::print(int* value)
{
  value[-1] = 40; 
}

UDS_030_AbstractProductA* UDS_030_ConcreateFactory1::createProductA()
{
  return new UDS_030_ConcreateProductA1;
}

UDS_030_AbstractProductB* UDS_030_ConcreateFactory1::createProductB()
{
  return new UDS_030_ConcreateProductB1;
}

UDS_030_AbstractProductA* UDS_030_ConcreateFactory2::createProductA()
{
  return new UDS_030_ConcreateProductA2;
}

UDS_030_AbstractProductB* UDS_030_ConcreateFactory2::createProductB()
{
  return new UDS_030_ConcreateProductB2;
}

void UDS_030_function()
{
  int p1[5] = { 0, };
  int p2[10] = { 0, };
  UDS_030_ConcreateFactory1 pFactory1;
  UDS_030_ConcreateFactory2 pFactory2;

  UDS_030_AbstractProductA* pA1 = pFactory1.createProductA();
  pA1->print(p1); //It's ok.

  UDS_030_AbstractProductB* pB1 = pFactory1.createProductB();
  pB1->print(p2); //It's ok.

  UDS_030_AbstractProductA* pA2 = pFactory2.createProductA();
  pA2->print(p2); //It's ok.

  UDS_030_AbstractProductB* pB2 = pFactory2.createProductB();
  pB2->print(p1); //@violation UNDERRUN.STATIC

  delete pA1;
  delete pB1;
  delete pA2;
  delete pB2;
}
