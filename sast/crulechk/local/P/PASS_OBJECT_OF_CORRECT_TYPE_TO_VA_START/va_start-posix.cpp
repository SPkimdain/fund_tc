
//@checker PASS_OBJECT_OF_CORRECT_TYPE_TO_VA_START
#include <iostream>
#include <stdarg.h>
#include <cstdarg>
  
int vout(int max, ...);

void POOCTTVS_(float a, ...) { 
  va_list list;
  va_start(list, a); //@violation PASS_OBJECT_OF_CORRECT_TYPE_TO_VA_START
  char *buffer;
  buffer = va_arg(list, char *);
  std::cout << "Message: " << buffer << std::endl;
  va_end(list);
}

extern "C" void POOCTTVS_2(std::string a, ...) { 
  va_list list;
  va_start(list, a); //@violation PASS_OBJECT_OF_CORRECT_TYPE_TO_VA_START
  char *buffer;
  buffer = va_arg(list, char *);
  std::cout << "Message: " << buffer << std::endl;
  va_end(list);
}

extern "C" void POOCTTVS_3(void (*a)(), ...) { 
  va_list list;
  va_start(list, a); //@violation PASS_OBJECT_OF_CORRECT_TYPE_TO_VA_START
  char *buffer;
  buffer = va_arg(list, char *);
  std::cout << "Message: " << buffer << std::endl;
  va_end(list);
}

extern "C" void POOCTTVS_4(int &a, ...) { 
  va_list list;
  va_start(list, a); //@violation PASS_OBJECT_OF_CORRECT_TYPE_TO_VA_START
  char *buffer;
  buffer = va_arg(list, char *);
  std::cout << "Message: " << buffer << std::endl;
  va_end(list);
}

extern "C" void POOCTTVS_5(char *a, ...) {
  va_list list;
  va_start(list, a);
  char *buffer;
  buffer = va_arg(list, char *);
  std::cout << "Message: " << buffer << std::endl;
  va_end(list);
}

extern "C" void POOCTTVS_6(double a, ...) {
  va_list list;
  va_start(list, a);
  char *buffer;
  buffer = va_arg(list, char *);
  std::cout << "Message: " << buffer << std::endl;
  va_end(list);
}

extern "C" void POOCTTVS_7(char a, ...) { 
  va_list list;
  va_start(list, a); //@violation PASS_OBJECT_OF_CORRECT_TYPE_TO_VA_START
  char *buffer;
  buffer = va_arg(list, char *);
  std::cout << "Message: " << buffer << std::endl;
  va_end(list);
}

extern "C" void POOCTTVS_8(short a, ...) { 
  va_list list;
  va_start(list, a); //@violation PASS_OBJECT_OF_CORRECT_TYPE_TO_VA_START
  char *buffer;
  buffer = va_arg(list, char *);
  std::cout << "Message: " << buffer << std::endl;
  va_end(list);
}


int POOCTTVS_Test(void)
{
   POOCTTVS_(1.0f, "Boom");
   return 0;
}

