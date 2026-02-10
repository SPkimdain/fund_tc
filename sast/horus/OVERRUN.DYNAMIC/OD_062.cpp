#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int OD_062_strncmp(const char * Str1, const char * Str2, int Count)
{       

    char *buffer =  (char *)malloc(10 * sizeof(char)); 

    if(buffer == NULL) 
    { 
        return 0;   
    }
    for(int i = 0; i < 11; i++)
    {      
        buffer[i] = i;          //@violation OVERRUN.DYNAMIC 
    }
  free(buffer);
  return 1;
}