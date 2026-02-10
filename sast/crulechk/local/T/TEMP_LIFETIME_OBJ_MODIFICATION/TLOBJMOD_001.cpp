//@checker TEMP_LIFETIME_OBJ_MODIFICATION

struct TLOBJMOD_001_Struct { 
  int a[6]; 
};

struct TLOBJMOD_001_Struct2 {
  int value;
};

TLOBJMOD_001_Struct TLOBJMOD_001_get_x(void) {
  TLOBJMOD_001_Struct result = { 1, 2, 3, 4, 5, 6 };
  return result;
}

TLOBJMOD_001_Struct& TLOBJMOD_001_get_y(TLOBJMOD_001_Struct& y) {
  return y;
}

TLOBJMOD_001_Struct2 TLOBJMOD_001_get_str2() {
  TLOBJMOD_001_Struct2 obj;
  obj.value = 10;
  return obj;
}

void TLOBJMOD_001_function(int bar) {
  ++(TLOBJMOD_001_get_x().a[0]); //@violation TEMP_LIFETIME_OBJ_MODIFICATION
  
  --(TLOBJMOD_001_get_str2().value); //@violation TEMP_LIFETIME_OBJ_MODIFICATION
  
  TLOBJMOD_001_Struct obj;
  ++(TLOBJMOD_001_get_y(obj).a[0]); //It's ok.
  
  
  TLOBJMOD_001_Struct obj2 = TLOBJMOD_001_get_x();
  ++(obj2.a[0]); //It's ok.
}

