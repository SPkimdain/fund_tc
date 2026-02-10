file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(DOUBLE_OPEN ${hdr} ${src})
