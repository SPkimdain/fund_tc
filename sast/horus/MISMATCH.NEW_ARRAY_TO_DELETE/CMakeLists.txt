file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(MISMATCH.NEW_ARRAY_TO_DELETE ${hdr} ${src})
