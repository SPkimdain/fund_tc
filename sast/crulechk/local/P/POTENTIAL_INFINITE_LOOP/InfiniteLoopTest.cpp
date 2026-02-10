//@checker POTENTIAL_INFINITE_LOOP
struct Node {
  Node* next;
};

void InfiniteLoopTest(Node* node) {
  int value = 0;
  /* Case1 : Infinite loop without a exit point. */
  for(;;) { //It's ok.
    return; 
  }

  for(;;) { //@violation POTENTIAL_INFINITE_LOOP
    value++;
  }

  do { //It's ok.
    value++;
  } while(0);
  
  while(1) { //It's ok.
    if(value > 10) {
      break;
    }
  }

  while(1) { //@violation POTENTIAL_INFINITE_LOOP
  }

  /* Case2 : Condition expression in a for is empty. */
  
  for(int i = 0; ; i++) { //@violation POTENTIAL_INFINITE_LOOP
    if(i > 10) {
      break;
    }
  }

  for(int i = 0; i < 10; i++) { //It's ok.
    value++;
  }

  /* Case3 : Loop counter {0} is Used with equal operator. 
     and Loop counter {0} is not changed sequentially. */
  
  for(int i =0; i != 100; i++) { //It's ok. sequance increase.
    value--;  
  }
  
  for(int i = 0; i != 100; i += 3) { //@violation POTENTIAL_INFINITE_LOOP
    value++;
  }
  
  for(int i =100; i != 0; i--) { //It's ok. sequence decrease.
    value--;
  }
  
  for(int i = 100; i != 0; i = i - 2) { //@violation POTENTIAL_INFINITE_LOOP
    value--;
  }

  int counter = 0;
  while(counter != 10) { //@violation POTENTIAL_INFINITE_LOOP
    counter += 2; 
  }
  
  counter = 0;
  while(counter != 10) { //It's ok.
    counter++;
  }

  bool flag = true;
  while(true == flag) { //It's ok. Bool type is excepted.
    value++;
    if(value > 20) {
      flag = false;
    }
  }

  while(!flag) { //it's ok. Bool type is excepted.
    value++;
    if(value > 10) {
      flag = true;
    }
  }
  
  /* Case4: Cannot find well bounded loop counter {0}. The loop may not be terminated. */
  
  for(int i = 0; i < 10; i--) { //@violation POTENTIAL_INFINITE_LOOP
    value++;
  }

  for(int i = 100; i >= 0; i += 2) { //@violation POTENTIAL_INFINITE_LOOP
    value++;
  }

  counter = 0;
  while(counter < 10) { //It's ok.
    counter++;
  }
  
  counter = 0;
  while(counter >= 10){ //@violation POTENTIAL_INFINITE_LOOP
    ++counter;
  }

  counter = 0;
  while(100 > counter) { //it's ok.
    counter++;
  }

  counter = 0;
  while(100 > counter) { //@violation POTENTIAL_INFINITE_LOOP
    counter--;
  }

  /* Case5: Loop counter {0} is not assigned in the loop. */
  
  for(Node* pIter = node; pIter != 0; pIter = pIter->next) { //It's ok.
    value++;
  }

  for(Node* pIter = node; pIter != 0; counter++) { //@violation POTENTIAL_INFINITE_LOOP
    value--;
  }

  Node* wIter = node;
  while(wIter != 0) { //@It's ok.
    wIter = wIter->next;
  }

  wIter = node;
  while(wIter != 0) { //@violation POTENTIAL_INFINITE_LOOP
    value++;
  }
  
  /* Case6: Loop counter {0} is assigned in for body. The loop may not be terminated. */ 
  
  for(int i = 0; i < 10; i++) { //@violation POTENTIAL_INFINITE_LOOP
    i++; //@b-violation POTENTIAL_INFINITE_LOOP
  }  
    
  for(Node* pIter = node; pIter != 0; counter++) { //@violation POTENTIAL_INFINITE_LOOP
    pIter = pIter->next; //@b-violation POTENTIAL_INFINITE_LOOP
  }
  
}

