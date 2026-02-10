
/* LM_068 - unknown struct */

struct LM_068_Obj {
  int value;
};

struct LM_068_Struct {
  LM_068_Obj* value;
};

struct LM_068_Struct2 {
  LM_068_Struct state;
};

extern LM_068_Struct2* LM_068_get_function();

void LM_068_function2(int flag) {
  if(flag > 10) {
    LM_068_get_function()->state.value = new LM_068_Obj; //It's ok.
  }    
}

void LM_068_function3(int flag) {
  LM_068_Struct2 obj;
  if(flag > 10) {
    obj.state.value = new LM_068_Obj; 
  }
} //@violation LEAK.MEMORY

