file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(UNREACHABLE_CODE ${hdr} ${src})
