file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(USELESS_ASSIGNMENT ${hdr} ${src})
