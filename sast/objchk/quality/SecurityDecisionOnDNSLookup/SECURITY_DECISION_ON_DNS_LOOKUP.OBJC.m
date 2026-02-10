char const *p ;
int decision(char *ip_addr_string) {
    struct hostent *hp;
    struct in_addr myaddr;
    char *tHost = "trustme.trusty.com";
    myaddr.s_addr = inet_addr(ip_addr_string);
    hp = (struct hostent *)gethostbyaddr((char *)&myaddr, sizeof(myaddr), AF_INET);
    if (hp && !strncmp(hp->h_name, tHost, sizeof(tHost))){ //@violation
        return 1; // TRUE
    }else{
        return 0; // FALSE
     }
}
