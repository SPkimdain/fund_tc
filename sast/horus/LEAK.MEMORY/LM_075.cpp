
extern void* CreatePen(int fnPenStyle, int nWidth, unsigned int crColor);
extern void DeleteObject(void* obj);

/* LM_075 - winapi1 */
void LM_074_function4(int flag) {
  void* handle = CreatePen(0, 0, 0);
  if(flag > 10) {
    DeleteObject(handle);
    return; //It's ok.
  }
  return; 
} //@violation LEAK.MEMORY



