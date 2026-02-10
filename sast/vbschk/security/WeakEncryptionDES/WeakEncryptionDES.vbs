set crypt = CreateObject("Chilkat.Crypt2")

crypt.CryptAlgorithm = "DES" '@violation
crypt.CipherMode = "ECB"
crypt.KeyLength = 64
crypt.EncodingMode = "hex"
crypt.SetEncodedKey "12345678","ascii"
Response.Write crypt.EncryptStringENC("ABC123")
