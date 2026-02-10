//@checker AUTHENTICATION_ATTEMPT_LIMIT
const int ID_SIZE = 100;
const int PASSWORD_SIZE = 100;

int getNextMessage(int socket, char** str, int size);
bool authenticationUser(char* id, char* password);

bool checkLogin() {
  char* id = new char[ID_SIZE];
  char* password = new char[PASSWORD_SIZE];
  int socket = 0;
  bool isValid = 0;
  
  while(isValid == 0) { //@violation AUTHENTICATION_ATTEMPT_LIMIT
    if(getNextMessage(socket, &id, ID_SIZE) > 0 && getNextMessage(socket, &password, PASSWORD_SIZE) > 0) {
      isValid = authenticationUser(id, password);
    }
  }
  
  delete[] id;
  delete[] password;
  
  return true;
}
  