
extern void* LoadBitmap(void* hInstance, char* lpBitmapName);
extern void DeleteObject(void* obj);

/* LM_075 - winapi2 */
void LM_074_function4(void* hinst, int flag) {
  void* handle = LoadBitmap(hinst, "name.bmp");
  if(flag > 10) {
    DeleteObject(handle);
    return; //It's ok.
  }
  return;
} //@violation LEAK.MEMORY



