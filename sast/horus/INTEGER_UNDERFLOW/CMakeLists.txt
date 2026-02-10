file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(INTEGER_UNDERFLOW ${hdr} ${src})
