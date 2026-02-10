file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(OS_COMMAND_INJECTION ${hdr} ${src})
