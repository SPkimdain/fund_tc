#include <iostream>

using namespace std;

/* TOS_030 - Abstract factory pattern */
struct TOS_030_Struct {
  int p1[5];
  int p2[10];
};

enum class TOS_030_Kind { PROA, PROB };

class TOS_030_ProductContainter {
public:
  TOS_030_ProductContainter(int init) : index(init) {}

  int getIndex() { return index; }
  
private:
  int index;

};

class TOS_030_AbstractProductA
{
public:
  virtual void print(int* value) = 0;
};

class TOS_030_AbstractProductB
{
public:
  virtual void print(int* value) = 0;

protected:
  int accessVal(int* value, int index) {
    return value[index];
  }
};

class TOS_030_ConcreateProductA1 : public TOS_030_AbstractProductA
{
public:
  void print(int* value);
};

class TOS_030_ConcreateProductA2 : public TOS_030_AbstractProductA
{
public:
  void print(int* value);
};

class TOS_030_ConcreateProductB1 : public TOS_030_AbstractProductB
{
public:
  void print(int* value);
};

class TOS_030_ConcreateProductB2 : public TOS_030_AbstractProductB
{
public:
  void print(int* value);
};

class TOS_030_AbstractFactory
{
public:
  virtual TOS_030_AbstractProductA* createProductA() = 0;
  virtual TOS_030_AbstractProductB* createProductB() = 0;
};

class TOS_030_ConcreateFactory1 : public TOS_030_AbstractFactory
{
public:
  virtual TOS_030_AbstractProductA* createProductA();
  virtual TOS_030_AbstractProductB* createProductB();
};

class TOS_030_ConcreateFactory2 : public TOS_030_AbstractFactory
{
public:
  virtual TOS_030_AbstractProductA* createProductA();
  virtual TOS_030_AbstractProductB* createProductB();
};

void TOS_030_ConcreateProductA1::print(int* value)
{
  value[3] = 10;
}

void TOS_030_ConcreateProductA2::print(int* value)
{
  value[6] = 10;
}

void TOS_030_ConcreateProductB1::print(int* value)
{
  value[3] = 40;
}

void TOS_030_ConcreateProductB2::print(int* value)
{
  static int printCount = 0;
  if(printCount > 8) {
    return;
  }

  TOS_030_ProductContainter cont(6);
  int ret = 0;
  for(int iter = 0; iter < printCount; ++iter) {
    ret += iter;
  }

  printCount++;

  cout << accessVal(value, cont.getIndex());

  return;
}

TOS_030_AbstractProductA* TOS_030_ConcreateFactory1::createProductA()
{
  return new TOS_030_ConcreateProductA1;
}

TOS_030_AbstractProductB* TOS_030_ConcreateFactory1::createProductB()
{
  return new TOS_030_ConcreateProductB1;
}

TOS_030_AbstractProductA* TOS_030_ConcreateFactory2::createProductA()
{
  return new TOS_030_ConcreateProductA2;
}

TOS_030_AbstractProductB* TOS_030_ConcreateFactory2::createProductB()
{
  return new TOS_030_ConcreateProductB2;
}

class TOS_030_Context {
public:
  TOS_030_Context(int* t) : targetVal(t) {}

  int* getTargetVal() { return targetVal; }

private:
  int* targetVal;
};

enum class TOS_030_VirtualEnum { TARGET, ABSTRACT, CONCRETE, NONE };

void TOS_030_function(int comp, int x, int y, TOS_030_VirtualEnum ve)
{
  TOS_030_Struct sb;

  if(comp == 10 && x + y > 10) {
    x = 10;
    y = 20;
  }
  else {
    return;
  }

  TOS_030_ConcreateFactory1 pFactory1;
  TOS_030_ConcreateFactory2 pFactory2;

  TOS_030_Context context(sb.p1);
  TOS_030_Context context2(sb.p2);

  
	TOS_030_AbstractProductA* obj = 0;
	TOS_030_AbstractProductB* obj2 = 0;

	TOS_030_AbstractProductA* pA1 = pFactory1.createProductA();

	TOS_030_AbstractProductB* pB1 = pFactory1.createProductB();

	TOS_030_AbstractProductA* pA2 = pFactory2.createProductA();

	TOS_030_AbstractProductB* pB2 = pFactory2.createProductB();	// TYPE_OVERRUN.STATIC

	int count = 0;

	do {
	  count++;
	  switch(ve) {
	  case TOS_030_VirtualEnum::ABSTRACT:
		obj = pA1;
		break;

	  case TOS_030_VirtualEnum::CONCRETE:
		obj = pA2;
		break;

	  case TOS_030_VirtualEnum::TARGET:
		obj2 = pB1;
		break;

	  case TOS_030_VirtualEnum::NONE:
		obj2 = pB2;
		break;

	  default:
		break;
	  }

	  if(obj != 0) {
		count++;
		obj->print(context2.getTargetVal()); //It's ok.
	  }

	  if(obj2 != 0) {
		count++;
		obj2->print(context.getTargetVal()); //@violation TYPE_OVERRUN.STATIC
	  }

	} while(obj != 0 && obj2 != 0 && count < 3);

	delete pA1;
	delete pB1;
	delete pA2;
	delete pB2;

}
