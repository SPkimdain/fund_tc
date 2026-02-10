// @checker RETURN_EMPTY_ARRAY_INSTEAD_OF_NULL
#define NULL 0
extern int printf ( const char * format, ... );
enum { INV_SIZE=20 };
 
typedef struct {
  int stockOfItem[INV_SIZE];
  int length;
} Inventory;
 
int *getStock(Inventory iv);
 
int main(void) {
  Inventory iv;
  int *item;
 
  iv.length = 0;
 
  /* Other code that might modify the inventory but still leave no items in it upon completion */
 
  item = getStock(iv);
 
  printf("Stock of first item in inventory: %d\n", item[0]);
   
  return 0;
}
 
int *getStock(Inventory iv) {
  if (iv.length == 0) {
    return NULL;		//@violation	RETURN_EMPTY_ARRAY_INSTEAD_OF_NULL
  }
  else {
    return iv.stockOfItem;
  }
}