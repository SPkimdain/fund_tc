file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(LEAK.MEMORY ${hdr} ${src})
