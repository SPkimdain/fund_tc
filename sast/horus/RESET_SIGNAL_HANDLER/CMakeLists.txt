file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(RESET_SIGNAL_HANLDER ${hdr} ${src})
