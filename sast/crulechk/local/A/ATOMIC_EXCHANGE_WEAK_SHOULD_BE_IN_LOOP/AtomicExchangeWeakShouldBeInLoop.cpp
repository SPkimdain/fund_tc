//@checker ATOMIC_EXCHANGE_WEAK_SHOULD_BE_IN_LOOP

 
struct data {
  struct data *next;
  /* ... */
};

extern data* atomic_load(data* v);
extern bool atomic_compare_exchange_weak(data* head, data** old, data* newHead);

 
extern void cleanup_data_structure(struct data *head);
 
int reorganize_data_structure(struct data *thread_arg) {
  struct data *ptr_to_head = thread_arg;
  struct data *old_head = atomic_load(ptr_to_head);
  struct data *new_head;
  bool success;
 
  /* ... Reorganize the data structure ... */
 
  success = atomic_compare_exchange_weak(ptr_to_head,  //@violation ATOMIC_EXCHANGE_WEAK_SHOULD_BE_IN_LOOP
                                         &old_head, new_head);
  if (!success) {
    cleanup_data_structure(new_head);
  }
  return success;
  
}