// @checker FIRST_COLUMN.PREPROCESSING

#include "header1.h"
  #include "header2.h"   // @violation FIRST_COLUMN.PREPROCESSING

#pragma once
  #pragma once    // @violation FIRST_COLUMN.PREPROCESSING

#pragma pack(4)
  #pragma pack(4)   // @violation FIRST_COLUMN.PREPROCESSING


#define TRUE 1
  #define FALSE 0  // @violation FIRST_COLUMN.PREPROCESSING

#ifdef TRUE
#define DEFINED_TRUE 1
#else
#define NOTDEFINED_TRUE 1
#endif


  #ifdef FALSE  // @violation FIRST_COLUMN.PREPROCESSING
  #define DEFINED_FALSE 1  // @violation FIRST_COLUMN.PREPROCESSING
  #else  // @violation FIRST_COLUMN.PREPROCESSING
  #define NOTDEFINED_FALSE 1  // @violation FIRST_COLUMN.PREPROCESSING
  #endif  // @violation FIRST_COLUMN.PREPROCESSING
