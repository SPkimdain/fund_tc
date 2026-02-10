//@checker CHECK.FIELD_ARRAY_LENGTH
typedef struct { 
  unsigned char modulus[128]; //@violation CHECK.FIELD_ARRAY_LENGTH
} key;

void CHKFAL_001_function() {
  key obj;
  
  return;
}
