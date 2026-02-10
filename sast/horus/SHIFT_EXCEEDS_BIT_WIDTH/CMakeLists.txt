file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(SHIFT_EXCEEDS_BIT_WIDTH ${hdr} ${src})
