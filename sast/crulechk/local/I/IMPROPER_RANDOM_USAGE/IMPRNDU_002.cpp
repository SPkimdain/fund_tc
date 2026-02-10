//@checker IMPROPER_RANDOM_USAGE

//#include <iostream>
//#include <random>

//using namespace std;

struct mersenne_twister_engine {
  mersenne_twister_engine(unsigned seed = 0);
};

struct random_device {
  unsigned operator()();
};

typedef unsigned time_t;
typedef mersenne_twister_engine mt19937;

void IMPRNDU_002_functon_dummy();
extern time_t time(time_t*);

void IMPRNDU_002_functon1() {
  IMPRNDU_002_functon_dummy();

  time_t tt;
  mt19937 engine; //@violation IMPROPER_RANDOM_USAGE

  for(int i = 0; i < 10; i++) {
    //cout << engine() << ", ";
  }

}

void IMPRNDU_002_functon2() {
  time_t tt;
  mt19937 engine(time(&tt)); //@violation IMPROPER_RANDOM_USAGE

  for(int i = 0; i < 10; i++) {
    //cout << engine() << ", ";
  }

}

void IMPRNDU_002_functon3() {
  time_t tt;
  random_device dev;
  mt19937 engine(dev()); //It's ok.

  for(int i = 0; i < 10; i++) {
    //cout << engine() << ", ";
  }

}
