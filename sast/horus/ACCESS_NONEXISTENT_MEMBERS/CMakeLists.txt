file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(ACCESS_NONEXISTENT_MEMBERS ${hdr} ${src})
