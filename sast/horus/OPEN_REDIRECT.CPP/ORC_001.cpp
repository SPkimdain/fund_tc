#include <stdio.h>
#include <stdlib.h>
#include <string>
#define Qstring const char*

using namespace std;

string allowedUrl[] = { "test.html" };  

class QDesktopServices {
public :
	void openUrl(string a) {
		return;
	}
};

extern string QUrl(const char* a) {return a;};
extern void urlchecker(const char* link) { };

int ORC_001_function1(const char* check) {
	if(check != NULL) {
		urlchecker(check);
		return 0;
	}
	else {
		return 1;
	}
}

int ORC_001_function(){
	Qstring link = getenv("reportName"); 
	QDesktopServices qs;
	if(ORC_001_function1(link) == 0) {
		qs.openUrl(QUrl(link));
	} else {
		qs.openUrl(QUrl(link));	//@violation OPEN_REDIRECT.CPP
	}
  return 0;
}
