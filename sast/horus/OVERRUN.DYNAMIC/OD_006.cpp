
/* OD_006 - interval size */
void OD_006_function(int size, int index) {
  if(size < 10) {
    char* arr = new char[size + 1];
    if(index == 11) {
      int ret = size + index;
      arr[index] = 'a'; //@violation OVERRUN.DYNAMIC
      ret++;
    }

    delete[] arr;
  }
}


