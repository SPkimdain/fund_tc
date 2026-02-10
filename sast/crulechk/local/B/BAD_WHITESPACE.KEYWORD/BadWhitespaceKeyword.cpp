// @checker BAD_WHITESPACE.KEYWORD

void BWSKEYWORD_001_function() {
  
  int cnt = 0;
  while(cnt < 10) { //@violation BAD_WHITESPACE.KEYWORD
    
  }

  while (cnt < 20) {
    
  }
  
  do {
    
  } while(cnt < 10); //@violation BAD_WHITESPACE.KEYWORD

  do {
    
  } while (cnt < 20);
  
  if (cnt < 10) {
    
  } else if(cnt < 20) { //@violation BAD_WHITESPACE.KEYWORD
    
  }
  else {

  }

  
  switch(cnt) { //@violation BAD_WHITESPACE.KEYWORD
  case 10:
    break;
  default:
    break;
  }

  switch (cnt) {
  case 5:
    break;
  }

  try {
    
  } catch(int e) { //@violation BAD_WHITESPACE.KEYWORD
    
  }
  catch (double ex) {

  }

  int sum = 0;
  for(int i = 0; i < 10; i++) { //@violation BAD_WHITESPACE.KEYWORD
    sum += i;
  }

  for (int i = 0; i < 5; i++) {
    sum += i;
  }
}
