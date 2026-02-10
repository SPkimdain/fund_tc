
/* DUTV_040 - hw_memcpy_s, src case4, TestWarning1 replaced2. */

typedef unsigned short VOS_UINT16;
typedef unsigned char  UCHAR;

struct DUTV_040_WebPacket {
  int len;
  UCHAR *data;
};


typedef struct tagDUTV_040_STRUCT_A
{
  VOS_UINT16 usRouteId;
  VOS_UINT16 usPara_02;
  VOS_UINT16 usPara_03;
  UCHAR ucPara_04;
} DUTV_040_STRUCT_A;

typedef struct tagSTRUCT_B
{
  VOS_UINT16 usRouteId;
  UCHAR ucPara_01;
  UCHAR ucPara_02;
  UCHAR ucPara_03;
} DUTV_040_STRUCT_B;

#define LEN 3

extern int hw_memcpy_s(void* dest, unsigned int destMax, const void* src, unsigned int count);

DUTV_040_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

void DUTV_040_function2(UCHAR* pucStart, char* pMsg) {
  DUTV_040_WebPacket* packet = getpacket(pMsg);

  UCHAR* pucSrc = packet->data;

  DUTV_040_STRUCT_A* pstSTRUCT_A;
  DUTV_040_STRUCT_B* pstSTRUCT_B;
  VOS_UINT16 usIndex;
  UCHAR ucTmpPara;

  pstSTRUCT_A = (DUTV_040_STRUCT_A*)(void*)pucStart;
  pstSTRUCT_B = (DUTV_040_STRUCT_B*)(void*)pucSrc;

  usIndex = pstSTRUCT_B->usRouteId;
  ucTmpPara = pstSTRUCT_B->ucPara_01;

  if(ucTmpPara == 1) {
    return;
  }
  else {
    hw_memcpy_s((pstSTRUCT_A + usIndex), //@violation DANGEROUS_USE_OF_TAINTED_VALUES
      LEN,
      pucSrc,
      LEN);
  }

}
