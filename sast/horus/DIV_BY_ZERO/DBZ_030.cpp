
/* DBZ_030 - Abstract factory pattern */
class DBZ_030_AbstractProductA
{
public:
  virtual void print(int* value) = 0;
};

class DBZ_030_AbstractProductB
{
public:
  virtual void print(int* value) = 0;
};

class DBZ_030_ConcreateProductA1 : public DBZ_030_AbstractProductA
{
public:
  void print(int* value);
};

class DBZ_030_ConcreateProductA2 : public DBZ_030_AbstractProductA
{
public:
  void print(int* value);
};

class DBZ_030_ConcreateProductB1 : public DBZ_030_AbstractProductB
{
public:
  void print(int* value);
};

class DBZ_030_ConcreateProductB2 : public DBZ_030_AbstractProductB
{
public:
  void print(int* value);
};

class DBZ_030_AbstractFactory
{
public:
  virtual DBZ_030_AbstractProductA* createProductA() = 0;
  virtual DBZ_030_AbstractProductB* createProductB() = 0;
};

class DBZ_030_ConcreateFactory1 : public DBZ_030_AbstractFactory
{
public:
  virtual DBZ_030_AbstractProductA* createProductA();
  virtual DBZ_030_AbstractProductB* createProductB();
};

class DBZ_030_ConcreateFactory2 : public DBZ_030_AbstractFactory
{
public:
  virtual DBZ_030_AbstractProductA* createProductA();
  virtual DBZ_030_AbstractProductB* createProductB();
};

void DBZ_030_ConcreateProductA1::print(int* value)
{
  if(*value != 0) {
    int ret = 1000 / *value;
  }
}

void DBZ_030_ConcreateProductA2::print(int* value)
{
  if(*value != 0) {
    int ret = 1000 / *value - 100;
  }
}

void DBZ_030_ConcreateProductB1::print(int* value)
{
  int ret = 1000 / *value; // DIV_BY_ZERO
}

void DBZ_030_ConcreateProductB2::print(int* value)
{
  int ret = 1000 / *value; 
}

DBZ_030_AbstractProductA* DBZ_030_ConcreateFactory1::createProductA()
{
  return new DBZ_030_ConcreateProductA1;
}

DBZ_030_AbstractProductB* DBZ_030_ConcreateFactory1::createProductB()
{
  return new DBZ_030_ConcreateProductB1;
}

DBZ_030_AbstractProductA* DBZ_030_ConcreateFactory2::createProductA()
{
  return new DBZ_030_ConcreateProductA2;
}

DBZ_030_AbstractProductB* DBZ_030_ConcreateFactory2::createProductB()
{
  return new DBZ_030_ConcreateProductB2;
}

void DBZ_030_function()
{
  int value1 = 100;
  int value2 = 0;

  DBZ_030_ConcreateFactory1 pFactory1;
  DBZ_030_ConcreateFactory2 pFactory2;

  DBZ_030_AbstractProductA* pA1 = pFactory1.createProductA();
  pA1->print(&value1); //It's ok.

  DBZ_030_AbstractProductB* pB1 = pFactory1.createProductB();
  pB1->print(&value2);  // @violation DIV_BY_ZERO

  DBZ_030_AbstractProductA* pA2 = pFactory2.createProductA();
  pA2->print(&value1); //It's ok.

  DBZ_030_AbstractProductB* pB2 = pFactory2.createProductB();
  pB2->print(&value2); 

  delete pA1;
  delete pB1;
  delete pA2;
  delete pB2;
}
