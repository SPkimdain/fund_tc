//@checker DANGEROUS_USE_OF_TAINTED_VALUES

/* DUTV_027 - pointer offset which occurred in a loop */

#define USHORT  unsigned short
#define UCHAR   unsigned char

void DoTotalTlv(UCHAR *pucDataAddress, USHORT usTlvMaxNum) { // set pucDataAddress as taint
  USHORT i;
  UCHAR *pucAddr = 0;
  USHORT usTlvLen = 0;

  pucAddr = pucDataAddress; // transitive

  // OUT-OF-BOUNDS READ     
  for(i = 0; i < usTlvMaxNum; i++) {
    // usTlvLen is taint, because it is coming from pucAddr       
    usTlvLen = *(USHORT*)(pucAddr + 1); //@violation DANGEROUS_USE_OF_TAINTED_VALUES
    // usTlvLen is taint, it will cause OOB read for the next loop   
    pucAddr += (4 + usTlvLen);
  }
}

