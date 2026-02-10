file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(MISSING.FUNCTION_DECLARATION ${hdr} ${src})
