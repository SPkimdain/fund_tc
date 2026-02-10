# Make sure C/CXX are enabled before doing this
enable_language(C CXX)

project(EdgpogTestSet)
cmake_minimum_required(VERSION 2.8)

enable_testing()

if(MSVC)
  add_definitions(-P)
endif()

add_subdirectory(ARGUMENT_NUMBER_MISMATCH)
add_subdirectory(BAD_FORMAT.VIRTUAL_FUNC_INIT)
add_subdirectory(BAD_INIT.PURE_VIRTUAL)
add_subdirectory(BAD_VLA_PARAMETER)
add_subdirectory(COND_COMP_MISMATCH)
add_subdirectory(FILENAME_IN_ANGLE_BRACKET_OR_DOUBLE_QUOTATION)
add_subdirectory(MISSING.FUNCTION_DECLARATION)
add_subdirectory(MISSING_FUNCTION_RETURN_TYPE)
add_subdirectory(PROHIBIT_DELETE_CONTAIN_ELEMENT_NUM)
add_subdirectory(VOID_PARAMETER_SHALL_NOT_BE_USED)
add_subdirectory(VOID_RETURN_VALUE_SHALL_NOT_BE_USED)
