// @checker BEWARE_THIRD_PARAM_IN_MAIN
#define NULL 0

extern int _putenv_s(const char* envname, const char* envval){}
extern int setenv(const char *envnamne, const char *envval, int overwrite){}
extern int puts ( const char * str );
 
int main(int argc, const char *argv[], const char *envp[]) {	//@violation BEWARE_THIRD_PARAM_IN_MAIN
	if (_putenv_s("MY_NEW_VAR", "new_value") != 0) {	//@b-violation BEWARE_THIRD_PARAM_IN_MAIN
	/* Handle error */
	}
	if (setenv("MY_NEW_VAR", "new_value", 1) != 0) {	//@b-violation BEWARE_THIRD_PARAM_IN_MAIN
	/* Handle error */
	}
	if (envp != NULL) {
		int i;
		for (i = 0; envp[i] != NULL; ++i) {		
			if (puts(envp[i]) == 1) {
			/* Handle error */
			}
		}
	}
	return 0;
}