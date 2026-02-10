file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(CALL_EVERY_FUNCTION_GLOBAL ${hdr} ${src})
