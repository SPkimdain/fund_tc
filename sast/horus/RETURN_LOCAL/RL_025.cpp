
/* RL_025 - return local field case1 */

class RL_025_Class {
public:
  RL_025_Class(int& v) : val(v) {}

private:
  int& val;
};

RL_025_Class RL_025_function(int& arg) {
  RL_025_Class obj(arg);

  return obj; //It's ok.
}

RL_025_Class RL_025_function2() {
  int x = 10;
  RL_025_Class obj2(x);

  return obj2; //@violation RETURN_LOCAL
}
