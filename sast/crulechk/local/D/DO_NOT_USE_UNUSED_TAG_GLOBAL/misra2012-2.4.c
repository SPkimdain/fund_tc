//@checker DO_NOT_USE_UNUSED_TAG_GLOBAL


void unusedTag(void)
{
	enum state { S_init, S_run, S_sleep }; //@violation DO_NOT_USE_UNUSED_TAG_GLOBAL
}



typedef struct record_t //@violation DO_NOT_USE_UNUSED_TAG_GLOBAL
{
	int key;
	int val;
} record1_t;
