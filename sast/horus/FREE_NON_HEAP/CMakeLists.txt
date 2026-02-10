file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(FREE_NON_HEAP ${hdr} ${src})
