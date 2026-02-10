file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(LEAK.RESOURCE ${hdr} ${src})
