//@checker CND_WAIT_SHOULDE_BE_IN_LOOP

int cnd_wait(int*, int*);
  
struct node_t {
  void *node;
  struct node_t *next;
};
  
struct node_t list;
static int lock;
static int condition;
  
void consume_list_element(void) {
  
  if (list.next == 0) {
    if (3 != cnd_wait(&condition, &lock)) { //@violation CND_WAIT_SHOULDE_BE_IN_LOOP
      /* Handle error */
    }
  }

  while (list.next == 0) {
    if (4 != cnd_wait(&condition, &lock)) {
      /* Handle error */
    }
  }

 
  /* Proceed when condition holds */
 
  
}