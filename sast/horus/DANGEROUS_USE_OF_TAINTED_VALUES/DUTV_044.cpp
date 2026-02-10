#include <stdlib.h>

/* DUTV_044 - struct object taint */

#define TEST_INT32 int
#define TEST_UINT16 unsigned short

#define TEST_VFS_ACCESS_READ 0


struct HEADER_EX {
  unsigned long ulNumEx;
};

extern TEST_INT32 open_test(char* name, int flag);
extern TEST_INT32 gen_sink_sptest(TEST_INT32 handle, HEADER_EX* header, int len);

extern char* g_acfileNameEx;


void DUTV_044_function(int len, char* src) {
  TEST_INT32 lFileHandle = -1;
  TEST_UINT16 usCrcHeadInFile;
  TEST_INT32 lRet;

  HEADER_EX* stFileHeaderEx = 0;          // object type

  lFileHandle = open_test(g_acfileNameEx, TEST_VFS_ACCESS_READ);

  if(0 > lFileHandle)

  {
    return;
  }

  stFileHeaderEx = (HEADER_EX*)malloc(sizeof(HEADER_EX));
  if(stFileHeaderEx == 0) {
    return;
  }

  lRet = gen_sink_sptest(lFileHandle, stFileHeaderEx, sizeof(TEST_UINT16));

  if(0 > lRet) { 
    free(stFileHeaderEx);
    return; 
  }


  for(int i = 0; i < stFileHeaderEx->ulNumEx; i++) { //@violation DANGEROUS_USE_OF_TAINTED_VALUES
    continue;
  }

  free(stFileHeaderEx);

  return;

}
