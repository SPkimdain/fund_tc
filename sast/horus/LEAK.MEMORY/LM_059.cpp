/* LM_059 - Linked-list style struct */

#define TABLE_SIZE 256

struct LM_059_Struct {
  int v;
  LM_059_Struct* next;
};

LM_059_Struct* table[TABLE_SIZE];

extern int LM_059_function_hash();

int LM_059_function_insert(int val) {
  LM_059_Struct* obj = new LM_059_Struct();
  obj->v = val;

  int hash = LM_059_function_hash();
  hash %= TABLE_SIZE;

  obj->next = table[hash];
  table[hash] = obj;

  return 0;
}

void LM_059_function2(int flag) {
 
  LM_059_function_insert(10);

  LM_059_function_insert(20);
  
  return;
} //It's ok.

void LM_059_function3() {
  int * ptr = new int[10];
} //@violation LEAK.MEMORY

