//@checker UNSALTED_ONE_WAY_HASH

extern void KrdMD5Encrypt(char* data, char* salt, char* outputData);

void GenerateHash(char* data)
{
 char hashedData[512] = {0};
 KrdMD5Encrypt( data, 0, hashedData ); //@violation UNSALTED_ONE_WAY_HASH
 /* ... */
 
}

