file(GLOB src "*.cpp")
file(GLOB hdr "*.hpp")

add_Library(ALREADY_OWNED_POINTER ${hdr} ${src})
