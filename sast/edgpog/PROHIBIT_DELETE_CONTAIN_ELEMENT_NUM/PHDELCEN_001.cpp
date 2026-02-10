//@checker PROHIBIT_DELETE_CONTAIN_ELEMENT_NUM 

int PHDELCEN_001_function(int* arr) {  
  if(arr != 0) {
    delete [2] arr; //@violation PROHIBIT_DELETE_CONTAIN_ELEMENT_NUM 
    return 1;
  }
  
  return 0;
}

