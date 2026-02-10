// @checker BAD_PARAM.PFM_SET_ERR.PF

#define PFM_SET_ERR(...) _pfmSetErrMsgExt2(1, 2, 3, 4, __VA_ARGS__)

extern void _pfmSetErrMsgExt2(char dummy1, char dummy2, char dummy3, char dummy4, 
  char* format, ...);
extern char* pfmGetErrMsg();

int badParamPFMSetErrTest() {
  PFM_SET_ERR("ZCOM0032323204", __FILE__, __LINE__, pfmGetErrMsg()); //@violation BAD_PARAM.PFM_SET_ERR.PF

  return 0;
}
