#ifndef _WEAK_PASSWORD_REQ_H_
#define _WEAK_PASSWORD_REQ_H_

typedef void MYSQL;

extern MYSQL *mysql_init(MYSQL *mysql);
extern MYSQL *mysql_real_connect(MYSQL *mysql, const char *host, const char *user, const char *passwd, const char *db, unsigned int port, const char *unix_socket, unsigned long client_flag);


#endif /* _WEAK_PASSWORD_REQ_H_ */
