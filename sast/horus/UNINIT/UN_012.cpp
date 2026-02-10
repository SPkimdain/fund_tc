
//TODO: for문을 1번만 반복하기 때문에 value의 값은 1로 판단되어 들어가지 않음.

/* UN_012 - for */
void UN_012_function() {
  int value = 0;
  int arg;
  for(int i = 0; i < 10; i++) {
    value++;
  }

  value += arg; //@violation UNINIT
  
}

