#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class QXmlQuery {
public :
	void setQuery(const char* xpath){};
};

extern void urlchecker(const char* query) { };	

int XPIC_001_function2(const char* query, int flag) {
	if(flag > 0) {
		urlchecker(query);
		return 0;
	}
	else {
		return 1;
	}
}

int XPIC_001_function(int flag) {
	//...
	const char* temp = getenv("myquery.xq");
	QXmlQuery xmlQuery;
	//char *queryTemp = new char;
	//char query1[] = "rhythmdb[@version='1.6']/entry[@type='";
	//char query2[] = "']";
	
	//sprintf(queryTemp, "%s%s%s", query1, temp, query2); 
	
  	if(XPIC_001_function2(temp, flag) == 0) {
		xmlQuery.setQuery(temp);	
	} else {
		xmlQuery.setQuery(temp);	//@violation XPATH_INJECTION.CPP
		//delete queryTemp;
		return 0;
	}
	//...
	//delete queryTemp;
	return 0;
}
    