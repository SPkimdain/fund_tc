//@checker MULTIPLE_BINDS_TO_SAME_PORT
#define AF_INET 0
#define SOCK_STREAM 1
#define SOL_SOCKET 1
#define SO_REUSEADDR 2
#define INADDR_ANY 100


struct sockaddr { 
  unsigned short sa_family; // address family, 2 bytes 
  char sa_data[14]; // IP address + Port number, 14 bytes 
};

struct in_addr {
  unsigned long s_addr;
};

struct sockaddr_in {
  short sin_family;
  unsigned short sin_port;
  in_addr sin_addr;
  char sin_zero[8];
};

extern int htonl(unsigned int host);
extern int socket(int inet, int stream, int flag);
extern int setsockopt(int s, int level, int optname, int* optval, int optlen);
extern int unlink(const char* path);
extern int bind(int socket, sockaddr* addr, int len);

void bind_socket(){
  int server_sockfd;
  int server_len;
  struct sockaddr_in server_address;
  int optval;
  unlink("server_socket");
  server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
  optval = 1;
  
  setsockopt(server_sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)); //@violation MULTIPLE_BINDS_TO_SAME_PORT
  
  server_address.sin_family = AF_INET;
  server_address.sin_port = 21;
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_len = sizeof(struct sockaddr_in);
  bind(server_sockfd, (struct sockaddr *) &server_address, server_len);
}
