
/* DUTV_041 - hw_memcpy_s, src case5, TestWarning1 replaced3. */

typedef unsigned short VOS_UINT16;
typedef unsigned char  UCHAR;

struct DUTV_041_WebPacket {
  int len;
  UCHAR *data;
};


typedef struct tagDUTV_041_STRUCT_A
{
  VOS_UINT16 usRouteId;
  VOS_UINT16 usPara_02;
  VOS_UINT16 usPara_03;
  UCHAR ucPara_04;
} DUTV_041_STRUCT_A;

typedef struct tagSTRUCT_B
{
  VOS_UINT16 usRouteId;
  UCHAR ucPara_01;
  UCHAR ucPara_02;
  UCHAR ucPara_03;
} DUTV_041_STRUCT_B;

#define LEN 3

extern int hw_memcpy_s(void* dest, unsigned int destMax, const void* src, unsigned int count);

DUTV_041_WebPacket* getpacket(char* pMsg); // The pointer of return can be set as taint. input scaffold.

int DUTV_041_function2(UCHAR* pucStart, char* pMsg) {
  DUTV_041_WebPacket* packet = getpacket(pMsg);

  UCHAR* pucSrc = packet->data;

  DUTV_041_STRUCT_A* pstSTRUCT_A;
  DUTV_041_STRUCT_B* pstSTRUCT_B;
  VOS_UINT16 usIndex;
  UCHAR ucTmpPara;
  int ret = 0;

  pstSTRUCT_A = (DUTV_041_STRUCT_A*)(void*)pucStart;
  pstSTRUCT_B = (DUTV_041_STRUCT_B*)(void*)pucSrc;

  usIndex = pstSTRUCT_B->usRouteId;
  ucTmpPara = pstSTRUCT_B->ucPara_01;

  if(1 == ucTmpPara) {
    ret++;
  }
  else {
    ret += 10;
  }

  hw_memcpy_s((pstSTRUCT_A + usIndex + 2), //@violation DANGEROUS_USE_OF_TAINTED_VALUES
    LEN,
    pucSrc,
    LEN);

  return ret;
}
