
/* RL_026 - return local field case2 */

class RL_026_Class {
public:
  RL_026_Class(int* v) : val(v) {}

private:
  int* val;
};

RL_026_Class RL_026_function(int* arg) {
  RL_026_Class obj(arg);

  return obj; //It's ok.
}


RL_026_Class RL_026_function2() {
  int x = 10;
  RL_026_Class obj2(&x);

  return obj2; //@violation RETURN_LOCAL
}
