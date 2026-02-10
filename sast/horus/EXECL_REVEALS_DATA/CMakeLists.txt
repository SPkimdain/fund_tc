file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(EXECL_REVEALS_DATA ${hdr} ${src})
