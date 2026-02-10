int main(int argc, char **argv){
  char arg[80] ;
  char cat[] = "cat ";
  char *command;
  size_t commandLength;
  fgets(arg, 80, stdin);
  commandLength = strlen(cat) + strlen(arg) + 1;
  command = (char *) malloc(commandLength);
  strncpy(command, cat, commandLength);
  strcat(command, argv[1], (commandLength ? strlen(cat)));
  system(command);  //@violation
  return 0;
}