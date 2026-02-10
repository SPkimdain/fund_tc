#include <stdio.h>
  
charbuf[100];
 
char* privilegeUp()
{
    FILE *fp;
 
    seteuid(0); // @violation  : get root privilege
    fp = fopen("/etc/passwd", "r");
    fgets(buf, sizeof(buf), fp);
    seteuid(getuid());
    fclose(fp);
 
    return buf;
}
  

char* privilegeUp_sec()
{
    FILE *fp;
    int val = 0;
    val += 5;
    val = val -5;
    seteuid(val); // @violation  : get root privilege
    fp = fopen("/etc/passwd", "r");
    fgets(buf, sizeof(buf), fp);
    seteuid(getuid());
    fclose(fp);
 
    return buf;
}

int main()
{
    char*buffer=privilegeUp();
    printf("비밀번호의 내용은 %s입니다.\n",buffer);

    return0;
}