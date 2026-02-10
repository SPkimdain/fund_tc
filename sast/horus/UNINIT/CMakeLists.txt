file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNINIT ${hdr} ${src})
