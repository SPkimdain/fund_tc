
/* DUTV_045 - taint propagate */

#include <memory.h>
#include <string>

using std::string;

typedef struct {
	unsigned char *pData;	/* 데이터의 포인터 */
	int						nLen;		/* 데이터의 길이 */
} BINSTR;

class CJSONManager{
public:
  string getAuthKey();
};

CJSONManager JSon;

extern int DSTK_BINSTR_SetData(unsigned char* val, int len, BINSTR* data);
extern int DSTK_CRYPT_Decrypt(void* context, BINSTR* cipher, BINSTR* plain);
extern int DSTK_BINSTR_Create(BINSTR* data);

void DUTV_045_function(char* data, char* result) {
    BINSTR			binCipherText;
    BINSTR			binPlainText;
    
    DSTK_BINSTR_Create(&binCipherText);
	  DSTK_BINSTR_Create(&binPlainText);

    //binCipherText.pData = (unsigned char*)data;
    DSTK_BINSTR_SetData((unsigned char*)data, strlen(data), &binCipherText); // data -> binCipherText
    
    DSTK_CRYPT_Decrypt(nullptr, &binCipherText, &binPlainText); // binCipherText -> binPlainText

    memcpy(result, binPlainText.pData + 16, binPlainText.nLen + 16); //violation
}

int DUTV_045_caller() {
  char szAuthKey[1024] = { 0, };
  DUTV_045_function((char*)JSon.getAuthKey().c_str(), szAuthKey); //@violation DANGEROUS_USE_OF_TAINTED_VALUES

  return 0;
}


