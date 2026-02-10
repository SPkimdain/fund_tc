
/* RL_027 - return local field case2 */

class RL_027_Class {
public:
  RL_027_Class(int* v) : val(v) {}

private:
  int* val;
};

RL_027_Class RL_027_function(int& flag) {
  int* arg = &flag;
  RL_027_Class obj(arg);

  return obj; //It's ok.
}


RL_027_Class RL_027_function2() {
  int first = 200;
  int* arg = &first;
  RL_027_Class obj2(arg);

  return obj2; //@violation RETURN_LOCAL
}
