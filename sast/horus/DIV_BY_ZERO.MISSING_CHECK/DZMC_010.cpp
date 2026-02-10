
/* DZMC_010 - deep fiedls */
struct DZMC_010_Struct1 {
  char flag;
  int value;
};

struct DZMC_010_Struct2 {
  DZMC_010_Struct1 ndObj1;
};

struct DZMC_010_Struct3{
  DZMC_010_Struct2 ndObj2;
};

int DZMC_010_function(int flag, DZMC_010_Struct3& obj) {
  int v = 1053;

  if(obj.ndObj2.ndObj1.value != 0) {
    obj.ndObj2.ndObj1.flag = 'y';
  }

  return 1000 / obj.ndObj2.ndObj1.value; //@violation DIV_BY_ZERO.MISSING_CHECK
}

