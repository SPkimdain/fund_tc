
/* UDD_006 - interval size */
void UDD_006_function(int size, int index) {
  if(size < 10) {
    char* arr = new char[size + 1];
    if(index == -1) {
      int ret = size + index;
      arr[index] = 'a'; //@violation UNDERRUN.DYNAMIC
      ret++;
    }

    delete[] arr;
  }
}


