file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(PROCESS_CONTROL ${hdr} ${src})
