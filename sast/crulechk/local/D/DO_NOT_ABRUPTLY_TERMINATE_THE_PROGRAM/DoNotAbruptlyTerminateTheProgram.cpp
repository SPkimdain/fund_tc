//@checker DO_NOT_ABRUPTLY_TERMINATE_THE_PROGRAM

extern int atexit (void (*func)(void)) noexcept;
 
using namespace std; 
 
 
 void throwing_func_sub() noexcept(false) 
{

throw 1; //@violation DO_NOT_ABRUPTLY_TERMINATE_THE_PROGRAM

}


void throwing_func() noexcept(false) 
{

throwing_func_sub();
}


void f() noexcept(true) { // Not invoked by the program except as an exit handler.

  throwing_func();

}
  
int main() {
	
	f();
  if (0 != atexit(f)) {
    // Handle error
  }
  // ... 
}

