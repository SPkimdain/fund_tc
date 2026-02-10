file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(IMPROPER_NULL_TERMINATION ${hdr} ${src})
