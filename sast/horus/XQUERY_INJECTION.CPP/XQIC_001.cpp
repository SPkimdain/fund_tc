#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

class QSqlQuery {
public :
	void prepare(const char* xpath){};
	void exec(){};
	void exec(const char* xpath){};
};

extern void urlchecker(const char* query) { };	

int XQIC_001_function2(const char* query, int flag) {
	if(flag > 0) {
		urlchecker(query);
		return 0;
	}
	else {
		return 1;
	}
}

int XQIC_001_function(int flag) {
	//...
	const char* temp = getenv("myquery.xq");
	QSqlQuery query;
	//char *queryTemp = new char;
	//char query1[] = "INSERT INTO employee (id, name, salary) VALUES (1001, '";
	//char query2[] = "', 65000)";
	
	//sprintf(queryTemp, "%s%s%s", query1, temp, query2);
	
  	if(XQIC_001_function2(temp, flag) == 0) {
    	query.prepare(temp);
		query.exec();
	} else {
		query.exec(temp);			//@violation XQUERY_INJECTION.CPP
		//delete queryTemp;
		return 0;
	}
	//...
	//delete queryTemp;
	return 0;
}