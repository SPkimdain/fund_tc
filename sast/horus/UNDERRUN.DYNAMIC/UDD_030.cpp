
/* UDD_030 - Abstract factory pattern */
class UDD_030_AbstractProductA
{
public:
  virtual void print(int* value) = 0;
};

class UDD_030_AbstractProductB
{
public:
  virtual void print(int* value) = 0;
};

class UDD_030_ConcreateProductA1 : public UDD_030_AbstractProductA
{
public:
  void print(int* value);
};

class UDD_030_ConcreateProductA2 : public UDD_030_AbstractProductA
{
public:
  void print(int* value);
};

class UDD_030_ConcreateProductB1 : public UDD_030_AbstractProductB
{
public:
  void print(int* value);
};

class UDD_030_ConcreateProductB2 : public UDD_030_AbstractProductB
{
public:
  void print(int* value);
};

class UDD_030_AbstractFactory
{
public:
  virtual UDD_030_AbstractProductA* createProductA() = 0;
  virtual UDD_030_AbstractProductB* createProductB() = 0;
};

class UDD_030_ConcreateFactory1 : public UDD_030_AbstractFactory
{
public:
  virtual UDD_030_AbstractProductA* createProductA();
  virtual UDD_030_AbstractProductB* createProductB();
};

class UDD_030_ConcreateFactory2 : public UDD_030_AbstractFactory
{
public:
  virtual UDD_030_AbstractProductA* createProductA();
  virtual UDD_030_AbstractProductB* createProductB();
};

void UDD_030_ConcreateProductA1::print(int* value)
{
  value[3] = 10;
}

void UDD_030_ConcreateProductA2::print(int* value)
{
  value[6] = 10;
}

void UDD_030_ConcreateProductB1::print(int* value)
{
  value[3] = 40;
}

void UDD_030_ConcreateProductB2::print(int* value)
{
  value[-6] = 40; 
}

UDD_030_AbstractProductA* UDD_030_ConcreateFactory1::createProductA()
{
  return new UDD_030_ConcreateProductA1;
}

UDD_030_AbstractProductB* UDD_030_ConcreateFactory1::createProductB()
{
  return new UDD_030_ConcreateProductB1;
}

UDD_030_AbstractProductA* UDD_030_ConcreateFactory2::createProductA()
{
  return new UDD_030_ConcreateProductA2;
}

UDD_030_AbstractProductB* UDD_030_ConcreateFactory2::createProductB()
{
  return new UDD_030_ConcreateProductB2;
}

void UDD_030_function()
{
  int* p1 = new int[5];
  if(p1 == 0) {
    return;
  }

  int* p2 = new int[10];
  if(p2 == 0) {
    return;
  }

  UDD_030_ConcreateFactory1 pFactory1;
  UDD_030_ConcreateFactory2 pFactory2;

  UDD_030_AbstractProductA* pA1 = pFactory1.createProductA();
  pA1->print(p1); //It's ok.

  UDD_030_AbstractProductB* pB1 = pFactory1.createProductB();
  pB1->print(p2); //It's ok.

  UDD_030_AbstractProductA* pA2 = pFactory2.createProductA();
  pA2->print(p2); //It's ok.

  UDD_030_AbstractProductB* pB2 = pFactory2.createProductB();
  pB2->print(p1); //@violation UNDERRUN.DYNAMIC

  delete pA1;
  delete pB1;
  delete pA2;
  delete pB2;

  delete[] p1;
  delete[] p2;
}
