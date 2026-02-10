#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

/* OSCI_005 - std string operator+=() */

using namespace std;

void OSCI_005_function() {
  char cmd[80] = { 0, };

  fgets(cmd, 80, stdin);

  string newCmd = "/opt/";
  newCmd += cmd;

  system(newCmd.c_str()); //@violation OS_COMMAND_INJECTION


  return;
}
