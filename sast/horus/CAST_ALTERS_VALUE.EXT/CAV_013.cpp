/* function call, signed -> unsigned */

void CAV_013_function1(bool flag, unsigned int arg){
  arg++;
}

void CAV_013_function2() {
  CAV_013_function1(true, (unsigned int)-1); //It's ok.

  CAV_013_function1(true, -50000); //@violation CAST_ALTERS_VALUE.EXT
}



