//@checker RACE_CONDITION.SWITCH

extern int printf ( const char * format, ... );
typedef int time_t;
struct stat {
	int st_ctime;
};

int foo(void){
	struct stat *sb;
	time_t timer;
	lstat("bar.sh",sb);
	printf("%d\n",sb->st_ctime);
	switch(sb->st_ctime % 2)	//@violation RACE_CONDITION.SWITCH
	{	
		case 0: printf("One option\n");
		break;
		case 1: printf("another option\n");
		break;
		default: printf("huh\n");
		break;
	}
	return 0;
}