//@checker PROHIBIT_DELETE_CONTAIN_ELEMENT_NUM 

int PHDELCEN_002_function(int* arr, int* arr2) {  
  if(arr == 0) {
    return 1;
  }

  delete [2] arr; //@violation PROHIBIT_DELETE_CONTAIN_ELEMENT_NUM 
  
  delete [] arr2; //It's ok.

  return 0;
}

