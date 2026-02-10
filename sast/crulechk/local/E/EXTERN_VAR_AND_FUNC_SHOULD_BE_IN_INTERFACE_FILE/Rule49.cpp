//@checker EXTERN_VAR_AND_FUNC_SHOULD_BE_IN_INTERFACE_FILE

#include "Rule49.hpp"

extern int extern_global_in_cpp;   //@violation EXTERN_VAR_AND_FUNC_SHOULD_BE_IN_INTERFACE_FILE
int global_in_cpp;


void function_decl_in_cpp(); //@violation EXTERN_VAR_AND_FUNC_SHOULD_BE_IN_INTERFACE_FILE
