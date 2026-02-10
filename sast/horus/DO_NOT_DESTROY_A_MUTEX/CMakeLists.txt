file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(DO_NOT_DESTROY_A_MUTEX ${hdr} ${src})
