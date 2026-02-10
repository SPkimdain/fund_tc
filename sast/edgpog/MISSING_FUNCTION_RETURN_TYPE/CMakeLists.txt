file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(MISSING_FUNCTION_RETURN_TYPE ${hdr} ${src})
