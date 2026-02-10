file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(NULL_DEREF.MALLOC_FAILED ${hdr} ${src})
