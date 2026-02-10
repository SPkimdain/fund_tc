file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(NEGATIVE_MOD_OPERATION ${hdr} ${src})
