file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(MISMATCH.MALLOC_TO_DELETE ${hdr} ${src})
