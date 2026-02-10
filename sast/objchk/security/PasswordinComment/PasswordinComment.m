/* password : a!2@3b4a */ // @violation
/* 비밀번호 : a!2@3b4a */ // @violation
/* password : a!2@3b4 (SAFE since not a password format) */
/* password : a12b3cd5 (SAFE since not a password format) */

// pwd is admin
int verfiyAuth(char *ipasswd, char *orgpasswd){
  char *admin = "admin";
  if(strncmp(ipasswd, orgpasswd, sizeof(ipasswd)) != 0){
    printf("Authentication Fail!\n");
  }
  return admin;
}
