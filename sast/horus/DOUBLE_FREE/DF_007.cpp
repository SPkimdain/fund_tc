#include <stdio.h>
#include <stdlib.h>

/* DF_007 - mem2 from opus */
char value_1 = 'a';
char value_2 = 'a';

void DF_007_function(){
  char *message = (char*)malloc(100);
  int message_type;
  int flag = false;

  scanf("%d", &message_type);

  /* Initialize message and message_type */

  if(message_type == value_1) {
    /* Process message type 1 */
    free(message);
    flag = true;
  }
  /* ...*/
  if(message_type == value_2) {
    /* Process message type 2 */
    free(message); //@violation DOUBLE_FREE
    flag = true;
    return;
  }

  if(message_type != value_1) {
    free(message);
    flag = true;
  }


  return;
}
