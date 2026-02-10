file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(SHIFT_NEGATIVE ${hdr} ${src})
