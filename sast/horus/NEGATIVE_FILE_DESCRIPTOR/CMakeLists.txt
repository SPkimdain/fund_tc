file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(NEGATIVE_FILE_DESCRIPTOR ${hdr} ${src})
