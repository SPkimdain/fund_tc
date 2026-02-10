//@checker MISSING_MESSAGE_ID_WHEN_GENERATING_MAC
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <time.h>

/* MMIGM_001 - simple case 1 */

#define CSNBMGN_LENGTH 512
#define MAC_PROCESSING_RULE "X9.9-1  "
#define SEGMENT_FLAG "ONLY    "
#define MAC_LENGTH "HEX-9   "
#define CHAINING_VECTOR_SIZE 18

extern void CSNBMGN(int* returnCode, int* ressonCode, int* exitDataLength, const char* exitData,
  const char* macKeyID, int* textLength, const char* text, int* ruleArrayCount, char* ruleArray,
  const char* chainingVector, const char* macValue);

extern void CSNBMGN1(int* returnCode, int* ressonCode, int* exitDataLength, const char* exitData,
  const char* macKeyID, int* textLength, const char* text, int* ruleArrayCount, const char** ruleArray,
  const char* chainingVector, const char* macValue, int* textIDIn);

extern void attach_macValue_to_sendingmsg(const char* macValue);
extern void attach_timestamp_to_sendingmsg(const char* timestamp);

extern int recv(int sockfd, void *buf, size_t len, int flags);


void MMIGM_001_function(int sockfd, int flow, char* inputText) {
  recv(sockfd, inputText, CSNBMGN_LENGTH, 0);

  char text[CSNBMGN_LENGTH] = { 0, };
  char ruleArray[3][CSNBMGN_LENGTH] = { 0, };
  char chainingVector[CHAINING_VECTOR_SIZE] = { 0, };
  char macValue[CSNBMGN_LENGTH] = { 0, };
  char macKeyID[CSNBMGN_LENGTH] = { 0, };

  int return_code = 0;
  int reason_code = 0;  
  int ruleArrayCount = 3; /* 3 rule array elements */
  memset(ruleArray, ' ', sizeof(ruleArray));
  /* Clear rule array */
  memcpy(ruleArray[0], MAC_PROCESSING_RULE, 8); /* 1st rule array element */
  memcpy(ruleArray[1], SEGMENT_FLAG, 8); /* 2nd rule array element */
  memcpy(ruleArray[2], MAC_LENGTH, 8); /* 3rd rule array element */

  memset(chainingVector, 0x00, CHAINING_VECTOR_SIZE);
  /* Clear chaining vector */
  memset(macValue, 0x00, sizeof(macValue));
  /* Clear MAC value */

  if(flow == 1) {
    int textLength = strlen(inputText) + 1; /* Length of MAC text */
    memcpy(text, inputText, textLength); /* Define MAC input text */

    /* Generate a MAC based on input text */
    CSNBMGN( //@violation MISSING_MESSAGE_ID_WHEN_GENERATING_MAC
      &return_code,
      &reason_code,
      NULL, /* exit_data_length */
      NULL, /* exit_data */
      macKeyID, /* Output from Key_Generate */
      &textLength,
      text,
      &ruleArrayCount,
      &ruleArray[0][0],
      chainingVector,
      macValue);


    /* Check the return/reason codes. Terminate if there is an error. */
    if(return_code != 0 || reason_code != 0) {
      /* MAC Generate Failed */
      return;
    }
    else {
      /* MAC_Generate successful */
      attach_macValue_to_sendingmsg(macValue);
    }

  }
  else {
    time_t ltime;
    time(&ltime); //timestamp.
    strcat(inputText, ctime(&ltime)); //Append timestamp.

    int textLength = strlen(inputText) + 1; /* Length of MAC text */
    memcpy(text, inputText, textLength); /* Define MAC input text */

    /* Generate a MAC based on input text */
    CSNBMGN( //It's ok.
      &return_code,
      &reason_code,
      NULL, /* exit_data_length */
      NULL, /* exit_data */
      macKeyID, /* Output from Key_Generate */
      &textLength,
      text,
      &ruleArrayCount,
      &ruleArray[0][0],
      chainingVector,
      macValue);


    /* Check the return/reason codes. Terminate if there is an error. */
    if(return_code != 0 || reason_code != 0) {
      /* MAC Generate Failed */
      return;
    }
    else {
      /* MAC_Generate successful */
      attach_macValue_to_sendingmsg(macValue);
      attach_timestamp_to_sendingmsg(ctime(&ltime));
    }
  }

}
