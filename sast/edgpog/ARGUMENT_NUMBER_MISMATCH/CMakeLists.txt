file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(ARGUMENT_NUMBER_MISMATCH ${hdr} ${src})
