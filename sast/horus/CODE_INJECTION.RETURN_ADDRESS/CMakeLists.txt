file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(CODE_INJECTION.RETURN_ADDRESS ${hdr} ${src})
