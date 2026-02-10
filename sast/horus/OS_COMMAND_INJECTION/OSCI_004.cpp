#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

/* OSCI_004 - std string operator+() */

using namespace std;

void OSCI_004_function() {
  char cmd[80] = { 0, };

  fgets(cmd, 80, stdin);

  string data = "/opt/";
  string newCmd = data + cmd;
  
  system(newCmd.c_str()); //@violation OS_COMMAND_INJECTION
  

  return;
}

