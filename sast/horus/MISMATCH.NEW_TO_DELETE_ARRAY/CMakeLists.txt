file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(MISMATCH.NEW_TO_DELETE_ARRAY ${hdr} ${src})
