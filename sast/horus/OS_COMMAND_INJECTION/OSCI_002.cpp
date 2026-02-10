#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* OSCI_002 - sanitize */

void OSCI_002_function1() {
  char arg[80];
  char cat[] = "cat ";
  char *command = 0;
  int commandLength = 0;
  
  fgets(arg,80,stdin);
  if(strpbrk(arg, ";\"'.")){
    return;
  }
  
  commandLength = strlen(cat) + strlen(arg) + 1;  
  command = (char *) malloc(commandLength);
  
  if(command == 0) {
    return;
  }
  
  strncpy(command, arg, commandLength);
  strncat(command, cat, (commandLength - strlen(cat)));
  
  system(command); //It's ok.
  
  free(command);
  
  return;
}


void OSCI_002_function2() {
  char arg[80];
  char cat[] = "cat ";
  char *command = 0;
  int commandLength = 0;

  fgets(arg, 80, stdin);
  commandLength = strlen(cat) + strlen(arg) + 1;
  command = (char *)malloc(commandLength);

  if(command == 0) {
    return;
  }

  strncpy(command, arg, commandLength);
  strncat(command, cat, (commandLength - strlen(cat)));

  if(strpbrk(arg, ";\"'.")){
    free(command);
    return;
  }

  system(command); //It's ok.

  free(command);

  return;
}


void OSCI_002_function3() {
  char arg[80];
  char cat[] = "cat ";
  char *command = 0;
  int commandLength = 0;

  fgets(arg, 80, stdin);
  commandLength = strlen(cat) + strlen(arg) + 1;
  command = (char *)malloc(commandLength);

  if(command == 0) {
    return;
  }

  strncpy(command, arg, commandLength);
  strncat(command, cat, (commandLength - strlen(cat)));

  system(command); //@violation OS_COMMAND_INJECTION

  free(command);

  return;
}
