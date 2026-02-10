//@checker TAKE_CARE_WHEN_USING_RENAME

extern int rename(char* src, char* dst);

int TCWURNAME_001_function(char* src_file, char* dest_file) {
  
  if(rename(src_file, dest_file) != 0) { //@violation TAKE_CARE_WHEN_USING_RENAME
    return -1;
  }
    
  return 0;
}
