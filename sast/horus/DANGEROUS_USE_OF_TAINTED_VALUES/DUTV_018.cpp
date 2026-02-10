//@checker DANGEROUS_USE_OF_TAINTED_VALUES

/* DUTV_018 - Support setting parameter of API(none of direct calling in one module) as taint case2 */

struct DUTV_018_Message {
  char* data;
  int length;
};

extern void hw_memcpy(char* dst, char* src, int size);

extern char* DUTV_018_getSafeSrc();
extern int DUTV_018_getSize();

struct DUTV_018_tagCommandGroup {
  char    szCommand[16];  // command type       
  unsigned long(*pfnCommandProc)(DUTV_018_Message* pMsg);  // process function
};

unsigned long LOAD_CliShowMulti(DUTV_018_Message* pMsg) { // pMsg is taint          
  char buf[10];
  
  char* src = DUTV_018_getSafeSrc();
  int len = DUTV_018_getSize();

  hw_memcpy(buf + pMsg->length, src, len);  //@violation DANGEROUS_USE_OF_TAINTED_VALUES

  return 1;
}
