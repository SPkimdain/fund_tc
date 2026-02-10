
/* DUTV_046 - dreamsecurity case2. */

#include <memory.h>
#include <string>

using std::string;

typedef struct {
	unsigned char *pData;	/* data pointer */
	int						nLen;		/* data size */
} BINSTR;

extern int DSTK_BINSTR_Create(BINSTR* data);
extern int DSTK_BINSTR_Delete(BINSTR* data);
extern int DSTK_BINSTR_SetData(unsigned char* val, int len, BINSTR* data);

extern int DSTK_BASE64_Decode(void* context, BINSTR* in, BINSTR* out);
extern int DSTK_CRYPT_SetKeyAndIV(void* context, int type, BINSTR* key, BINSTR* iv);
extern int DSTK_CRYPT_Decrypt(void* context, BINSTR* cipher, BINSTR* plain);

extern int getAuthKeyA(unsigned char* code, unsigned char* val, int len);
extern int getAuthKeyB(unsigned char* code, unsigned char* val, int len);

extern void* m_pContext;

class CJSONManager{
public:
  string getAuthKey();
};

CJSONManager JSon;

int SYM_ALG_SEED_CBC = 0;
unsigned char dummy = 10;
unsigned char* m_pAuthCode = &dummy;
int DSTK_OK = 0;

int DUTV_046_function(unsigned char* pAuthCode, char *data, char *result, int len)
{
	int				nRv		= DSTK_OK;
	unsigned char	key[16]	= {0x00,};
	unsigned char	iv[16]  = {0x00,};
	BINSTR			binKey;
	BINSTR			binIV;
	BINSTR			binCipherText;
	BINSTR			binPlainText;

	DSTK_BINSTR_Create(&binKey);
	DSTK_BINSTR_Create(&binIV);
	DSTK_BINSTR_Create(&binCipherText);
	DSTK_BINSTR_Create(&binPlainText);

	if (pAuthCode == 0 || data == 0 || result == 0 || len == 0)
	{
		nRv = 1;
		goto END;
	}

	getAuthKeyA(pAuthCode, key,  sizeof(key));
	getAuthKeyB(pAuthCode, iv  , sizeof(iv));

	DSTK_BINSTR_SetData(key,16, &binKey);
	DSTK_BINSTR_SetData(iv, 16, &binIV);
	DSTK_BINSTR_SetData((unsigned char*)data, strlen(data), &binCipherText);

	memset(key, 0x00, sizeof(key));
	memset(iv,  0x00, sizeof(iv));

	nRv = DSTK_BASE64_Decode(m_pContext, &binCipherText, &binCipherText);

	if(nRv != DSTK_OK)
	{
		goto END;
	}

	nRv = DSTK_CRYPT_SetKeyAndIV(m_pContext, SYM_ALG_SEED_CBC, &binKey, &binIV);
	
	if(nRv != DSTK_OK)
	{
		goto END;
	}

	nRv = DSTK_CRYPT_Decrypt(m_pContext, &binCipherText, &binPlainText);

	if(nRv != DSTK_OK)
	{
		goto END;
	}

	// gwkim++ 2023-03-07
	memcpy(result, binPlainText.pData + 16, binPlainText.nLen - 16);
	/*if (binPlainText.nLen <= 16)
	{
		goto END;
	}
	else
	{
		if (binPlainText.nLen >= len)
		{
			binPlainText.nLen = len - 1;
		}

		memcpy(result, binPlainText.pData + 16, binPlainText.nLen - 16);
	}*/

END:

	DSTK_BINSTR_Delete(&binKey);
	DSTK_BINSTR_Delete(&binIV);
	DSTK_BINSTR_Delete(&binCipherText);
	DSTK_BINSTR_Delete(&binPlainText);

	return 0;
}

// The value of (char*)JSon.getAuthKey().c_str() is encrypted,
// and the DUTV_046_function function performs decryption.
// A buffer overflow occurs when the decrypted value exceeds.
int DUTV_046_caller() {
  char szAuthKey[1024] = { 0, };
  DUTV_046_function(m_pAuthCode, (char*)JSon.getAuthKey().c_str(), szAuthKey, sizeof(szAuthKey)); //@violation DANGEROUS_USE_OF_TAINTED_VALUES

  return 0;
}

