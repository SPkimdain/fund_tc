// @checker WEAK_ENCRYPTION.HARDCODED_SALT
#define NULL 0
#define MAX_TEXT 512

void * crypt(const char * text, const char * salt);

void badSalt(const char * text) {
	char * out;
	out = (char *)crypt(text, "xp"); // @violation WEAK_ENCRYPTION.HARDCODED_SALT
}

void badSalt2(const char * text) {
	char * out;
	char os[20] = "xp";
	out = (char *)crypt(text, os); // @violation WEAK_ENCRYPTION.HARDCODED_SALT
}

void badSalt3(const char * text) {
	char * out;
	char os[20] = "xp";
	char * osClone = os;
	out = (char *)crypt(text, osClone); // @violation WEAK_ENCRYPTION.HARDCODED_SALT
}

void badSalt4(const char * text, char * os) {
	char * out;
	char salt[20] = "xp";
	if(text != NULL) {
		os = salt;
	}	
	out = (char *)crypt(text, os); // @violation WEAK_ENCRYPTION.HARDCODED_SALT	
}

void goodSalt(const char * text, const char * os) {
	char * out;
	out = (char *)crypt(text, os);
}

void goodSalt2(const char * text, char * os) {
	char * out;
	char salt[20] = "xp";
	if(text != NULL) {
		os = salt;
	} else {	
		out = (char *)crypt(text, os);
	}
}

