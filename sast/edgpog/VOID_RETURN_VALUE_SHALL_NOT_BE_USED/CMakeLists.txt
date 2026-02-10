file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(VOID_RETURN_VALUE_SHALL_NOT_BE_USED ${hdr} ${src})
