file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(INCORRECT_USE_OF_PLACEMENT_NEW ${hdr} ${src})
