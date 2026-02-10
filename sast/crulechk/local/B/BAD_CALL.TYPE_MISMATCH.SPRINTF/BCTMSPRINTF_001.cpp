//@checker BAD_CALL.TYPE_MISMATCH.SPRINTF 

#include <stdio.h>

#define MAX_SIZE 400

//Base

void BCTMSPRINTF_001_function()
{
	char a[100];
	char b[200];
	char buf[100];
	char safebuf[300];
	char bigbuf[MAX_SIZE];


	sprintf( buf, "%s%s", a, b ); //@violation BAD_CALL.TYPE_MISMATCH.SPRINTF 


	snprintf( buf, 300, "%s%s", a, b ); //@violation BAD_CALL.TYPE_MISMATCH.SPRINTF 


	sprintf( safebuf, "%s%s", a, b ); //Checking False Alarm


	snprintf( bigbuf, MAX_SIZE, "%s%S", a, b ); //Checking False Alarm
}
