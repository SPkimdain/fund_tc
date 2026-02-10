//@checker DANGEROUS_USE_OF_TAINTED_VALUES

/* DUTV_017 - Support setting parameter of API(none of direct calling in one module) as taint case1 */

struct DUTV_017_Message {
  char* data;
  int length;
};

extern void hw_memcpy(char* dst, char* src, int size);

struct DUTV_017_tagCommandGroup {
  char    szCommand[16];                                                          // comand type       
  unsigned long   (*pfnCommandProc)(DUTV_017_Message* pMsg);              // process function   }  
};

unsigned long LOAD_CliShowSingle(DUTV_017_Message* pMsg) { //pMsg is taint. The function name is written in scaffold list.
  char buf[10];
  hw_memcpy(buf, pMsg->data, pMsg->length); //@violation DANGEROUS_USE_OF_TAINTED_VALUES

  return 0;
}
