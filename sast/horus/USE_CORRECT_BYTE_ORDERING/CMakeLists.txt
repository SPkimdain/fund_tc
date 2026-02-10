file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(USE_CORRECT_BYTE_ORDERING ${hdr} ${src})
