//@checker NEVER_CREATE_CONTAINERS_OF_AUTO_PTRS

#include <vector>
#include <memory>

using namespace std;

class NCCOAP_c {};  
void NCCOAP_func( vector< auto_ptr< NCCOAP_c > >& myVec ) {  //@violation NEVER_CREATE_CONTAINERS_OF_AUTO_PTRS
  // After myObj2 is initialised myObj1 is a 0 ptr!
  //
  auto_ptr< NCCOAP_c > myObj1 = myVec[ 0 ];
  auto_ptr< NCCOAP_c > myObj2 = myObj1;

  vector< auto_ptr< NCCOAP_c > > myVec2;  //@violation NEVER_CREATE_CONTAINERS_OF_AUTO_PTRS
  
  vector< auto_ptr< NCCOAP_c > >** myVec3, myVec4;  //@violation NEVER_CREATE_CONTAINERS_OF_AUTO_PTRS
}

