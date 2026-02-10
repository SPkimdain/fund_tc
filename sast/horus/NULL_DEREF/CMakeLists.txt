file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(NULL_DEREF ${hdr} ${src})
