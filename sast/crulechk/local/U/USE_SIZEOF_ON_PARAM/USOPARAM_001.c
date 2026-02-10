//@checker USE_SIZEOF_ON_PARAM
/*
 * HMG Secure Coding Guide Exemplar Suite
 *
 * Published by Fasoo.com PA Business Division
 *
 * Copyright Fasoo.com
 *
 */

/*
 * Test case of rule 1-7
 * 버퍼 또는 자료형 크기 계산에 주의하라
(버퍼 크기 계산시 sizeof() 연산자를 사용하되, 포인터 타입에 대한 sizeof()
사용을 주의하라)

 */
#include "USOPARAM_001.h"

#define  MAP_ROW       20
#define  MAP_COLUMN   180
#define  MAX_SIZE     65535
#define  DATA_LIST    256


extern void readMapData(uint32 **data);
extern void setOriginData(uint16 *data);


void somecall(uint32  size, uint8*  dst,  uint8*  src)
{
    uint32  idx = 0U;
	if (size > 0) {
		for (idx = 0; idx < size ; idx++)  
		{
			dst[idx] = src[idx];
		}
	}
}

int autoever01_07_bad1 (void)
{
    struct  ecuInfo {
        uint8  vendorId[10];
        uint8  moduleId[5];
        uint32  versionCnt;
    } ecu1;
	
	uint8   canTPBuffer[MAX_SIZE] = { 0, };

    somecall(((1*10)*(1*5)*(4*1)), canTPBuffer, (uint8 *) &ecu1);	//@violation USE_SIZEOF_ON_PARAM

    return  0;
} 


int autoever01_07_good1 (void)
{
    struct  ecuInfo {
        uint8  vendorId[10];
        uint8  moduleId[5];
        uint32  versionCnt;
    } ecu1;
	
	uint8   canTPBuffer[MAX_SIZE] = { 0, };

    somecall(sizeof(ecu1), canTPBuffer, (uint8 *) &ecu1);

    return  0;
}


int autoever01_07_bad2 (void)
{
    uint32  mapData[MAP_ROW][MAP_COLUMN] = { 0, };
    uint8   canTPBuffer[MAX_SIZE] = { 0, };

	readMapData((uint32**)mapData);

    somecall((MAP_ROW*MAP_COLUMN), canTPBuffer, (uint8 *) mapData);	//@violation USE_SIZEOF_ON_PARAM

    return  0;
} 


int autoever01_07_good2 (void)
{
    uint32  mapData[MAP_ROW][MAP_COLUMN] = { 0, };
    uint8   canTPBuffer[MAX_SIZE] = { 0, };

	readMapData((uint32**)mapData);

    somecall(sizeof(mapData), canTPBuffer, (uint8 *) mapData);

    return  0;
}



int autoever01_07_bad3 (void)
{
    uint16  originData[DATA_LIST] = { 0, };
    uint8  canTPBuffer[MAX_SIZE] = { 0, };

	setOriginData(originData);

    somecall((sizeof(uint16 *) * DATA_LIST), canTPBuffer, (uint8 *) originData);

    return  0;
} 


int autoever01_07_good3 (void)
{
    uint16  originData[DATA_LIST] = { 0, };
    uint8  canTPBuffer[MAX_SIZE] = { 0, };

	setOriginData(originData);

    somecall((sizeof(uint32) * DATA_LIST), canTPBuffer, (uint8 *) originData);

    return  0;
}
