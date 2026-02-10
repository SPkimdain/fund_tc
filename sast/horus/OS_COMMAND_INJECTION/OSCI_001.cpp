#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OSCI_001_function() {
  char arg[80];
  char cat[] = "cat ";
  char *command = 0;
  int commandLength = 0;
  
  fgets(arg,80,stdin);
  
  commandLength = strlen(cat) + strlen(arg) + 1;  
  command = (char *) malloc(commandLength);
  
  if(command == 0) {
    return;
  }
  
  strncpy(command, arg, commandLength);
  strncat(command, cat, (commandLength - strlen(cat)));
  
  system(command); //@violation OS_COMMAND_INJECTION
  
  free(command);
  
  return;
}

