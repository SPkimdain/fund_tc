file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(CHECK_ALIGNMENT_OF_MEMORY ${hdr} ${src})
