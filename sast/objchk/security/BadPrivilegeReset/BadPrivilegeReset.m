#define APP_HOME "/var/tmp"
char buf[100];

char *privilegeDown()
{
    FILE *fp;

    chroot(APP_HOME); //@violation  [case #1] need to lower the privilege afterwards
    chdir("/");
    fopen("important_file", "r");
    fgets(buf, sizeof(buf), fp);
    fclose(fp);

    return buf;
}