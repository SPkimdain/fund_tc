
/* RL_021 - reference type */

struct RL_021_Struct {
  int x;
  int y;
};

RL_021_Struct& RL_021_function() {
  RL_021_Struct local;
  return local; //@violation RETURN_LOCAL
}

