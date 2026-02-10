//@checker SOCKET_IN_WRONG_STATE
#define INADDR_ANY 	0	
#define SOCK_STREAM	1
#define AF_INET		2

typedef char u_char;
typedef short u_short;
typedef long u_long;

struct in_addr {
  union {
    struct {
      u_char s_b1;
      u_char s_b2;
      u_char s_b3;
      u_char s_b4;
    } S_un_b;
    struct {
      u_short s_w1;
      u_short s_w2;
    } S_un_w;
  } S_un;
  u_long s_addr;
};

struct sockaddr_in {
        short   sin_family;
        u_short sin_port;
        struct  in_addr sin_addr;
        char    sin_zero[8];
};


//Base
extern int socket(int domain, int type, int protocol);
extern void closesocket(int);
extern int bind(int sockfd, struct sockaddr *addr, int addrlen);
extern long htonl(long hostlong);
extern int listen(int sockfd, int backlog);
extern int accept(int sockfd, struct sockaddr *addr, int*);
extern int send(int sockfd, const void *buf, int len, int flags);
extern int recv(int sockfd, void *buf, int len, int flags);
extern int connect(int sockfd, struct sockaddr *addr, int addrlen);

void T0082func1()
{
	int server_sockfd = 0;
	int server_len;
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = 21;
	server_address.sin_addr.s_addr = htonl( INADDR_ANY );
	server_len = sizeof( struct sockaddr_in );
	//Base01 - 가이드 예시
	bind( server_sockfd, ( struct sockaddr *)&server_address, server_len ); //@violation SOCKET_IN_WRONG_STATE
	closesocket(server_sockfd);
}

void T0082func2()
{
	int server_sockfd = 0;
	int server_len;
	struct sockaddr_in server_address;

	server_address.sin_family = AF_INET;
	server_address.sin_port = 21;
	server_address.sin_addr.s_addr = htonl( INADDR_ANY );
	server_len = sizeof( struct sockaddr_in );

	server_sockfd = socket( AF_INET, SOCK_STREAM, 0 );	
	//Base02 - 가이드 예시(listen시 bind가 없을 경우 )
	listen( server_sockfd, 5 ); //@violation SOCKET_IN_WRONG_STATE
	closesocket(server_sockfd);
}

void T0082func3()
{
	int server_sockfd = 0;
	int server_len;
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = 21;
	server_address.sin_addr.s_addr = htonl( INADDR_ANY );
	server_len = sizeof( struct sockaddr_in );
	
	server_sockfd = socket( AF_INET, SOCK_STREAM, 0 );	
	bind( server_sockfd, ( struct sockaddr *)&server_address, server_len ); 
	
	int clientSock;
	struct sockaddr_in clientAddr;
	int client_len;
	
	//Base03 - 가이드 예시(accept시 listen이 없을 경우)
	clientSock = accept( server_sockfd, ( struct sockaddr * )&clientAddr, &client_len ); //@violation SOCKET_IN_WRONG_STATE

	int dummySock = 10;
	//Base05 - 가이드 예시( connect되지 않은 소켓s)
	send( dummySock, "MSG", 4, 0 ); //@violation SOCKET_IN_WRONG_STATE

	//Base06 - 가이드 예시( connect되지 않은 소켓s)
	char buf[100];
	recv( dummySock, buf, 100, 0 ); //@violation SOCKET_IN_WRONG_STATE
	
	closesocket(server_sockfd);
}


void T0082func4()
{
	int server_sockfd = 0;
	int server_len;
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = 21;
	server_address.sin_addr.s_addr = htonl( INADDR_ANY );
	server_len = sizeof( struct sockaddr_in );
	
	server_sockfd = socket( AF_INET, SOCK_STREAM, 0 );	
	bind( server_sockfd, ( struct sockaddr *)&server_address, server_len ); 
	
	int clientSock;
	struct sockaddr_in clientAddr;
	int client_len;
	
	listen( server_sockfd, 5 );
		
	//Base04 - 가이드 예시(connet시 소켓이 이미 listen에 연결된 종류인 경우)
	connect( server_sockfd, ( struct sockaddr * )&server_address, server_len ); //@violation SOCKET_IN_WRONG_STATE
	
	closesocket(server_sockfd);
}
